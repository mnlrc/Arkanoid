/**
 * @file view.cpp
 * @author Manuel Rocca
 * @brief Source file for the View class
 * @date 2024z
 *
 */

#include "view.hpp"

View::View(const int width, const int height)
{
    setupAllegro(width, height);
}

View::~View()
{
    if (display_)
    {
        al_destroy_display(display_);
    }
};

void View::setupAllegro(const int width, const int height)
{
    display_ = al_create_display(width, height);

    init_test(al_init_primitives_addon(), "primitives");
    init_test(al_init_ttf_addon(), "TTF addon");
    font_ = al_load_ttf_font("font.ttf", FONT_SIZE, 0);
    init_test(font_, "font");
    init_test(display_, "display");
}

ALLEGRO_DISPLAY *View::get_display() const noexcept { return display_; }

void View::render_menu_model(const std::unique_ptr<MenuModel> &model)
{
    draw(model);
    al_flip_display();
}

void View::render_game_model(const std::unique_ptr<GameModel> &game_model)
{
    draw(game_model);
    al_flip_display();
}

void View::render_button(const Button &button)
{
    draw(button);
    al_flip_display();
}

void View::draw_window(const Model &model)
{
    // drawing main window
    const int window_width = model.get_width();
    const int window_height = model.get_height();
    const Color temp_inner_color = model.get_inner_color();
    const Color temp_outer_color = model.get_outer_color();

    ALLEGRO_COLOR window_inner_color = color_convertor(temp_inner_color);
    ALLEGRO_COLOR window_outer_color = color_convertor(temp_outer_color);

    al_draw_filled_rectangle(0, 0, window_width, window_height, window_inner_color);
    al_draw_rectangle(0, 0, window_width, window_height, window_outer_color, 4.0);
}

void View::draw(const std::unique_ptr<MenuModel> &model)
{
    draw_window(*model);

    std::vector<Button> buttons = model->get_buttons();

    for (size_t i = 0; i < NUMBER_OF_BUTTONS; i++)
    {
        draw(buttons[i]);
    }
}

void View::draw(const std::unique_ptr<GameModel> &game_model)
{
    draw_window(*game_model);

    std::shared_ptr<Racket> temp_racket = game_model->get_racket();
    draw(*temp_racket);

    std::vector<std::shared_ptr<Ball>> temp_balls = game_model->get_balls();
    for (auto &ball : temp_balls)
    {
        draw(*ball);
    }

    std::vector<std::vector<std::shared_ptr<Brick>>> temp_bricks = game_model->get_bricks();

    for (auto &bricks_row : temp_bricks)
    {
        for (auto &brick : bricks_row)
        {
            if (!brick->is_broken())
            {
                draw(*brick);
                Point center = brick->get_center();
                std::string str;
                try
                {
                    str = POWER_CHAR.at(brick->get_power_up());
                }
                catch (const std::exception &e)
                {
                    Logger::log("[ERROR] Exception when retrieving brick power up: " + std::string(e.what()));
                    str = "";
                }
                Color color = Color::BLACK;
                draw(center, str, color);
            }
        }
    }

    std::vector<std::shared_ptr<Circle>> temp_circles = game_model->get_circles();

    for (auto &circle : temp_circles)
    {
        draw(*circle);
    }

    Score temp_score = game_model->get_current_score();
    std::string score_string = "Score: " + std::to_string(temp_score.get_score());
    Point score_center = temp_score.get_center();
    Color score_color = temp_score.get_color();

    draw(score_center, score_string, score_color);

    std::vector<PowerUp> &power_ups = game_model->get_falling_power_ups();
    for (auto &power_up : power_ups)
    {
        if (power_up.is_falling())
        {
            draw(power_up);
        }
    }

    if (game_model->get_active_power_up().get_power() == Power::LASER)
    {
        std::vector<Laser> &lasers = game_model->get_lasers();

        for (auto &laser : lasers)
        {
            if (!laser.is_launched())
            {
                break;
            }
            if (laser.was_used())
            {
                continue;
            }
            draw(laser);
        }
    }
}

void View::draw(const Button &button)
{
    Rectangle temp_rec = button.get_rectangle();

    draw(temp_rec);

    Text temp_text = button.get_selected_text();

    Point text_center = temp_rec.get_center();
    std::string temp_string = temp_text.get_text();
    Color temp_color = temp_text.get_color();

    draw(text_center, temp_string, temp_color);
}

void View::draw(const Rectangle &rectangle)
{
    Point RECTANGLE_CENTER = rectangle.get_center();
    double RECTANGLE_WIDTH = rectangle.get_width();
    double RECTANGLE_HEIGHT = rectangle.get_height();

    // upper left
    double x1 = RECTANGLE_CENTER.x_ - (RECTANGLE_WIDTH / 2);
    double y1 = RECTANGLE_CENTER.y_ - (RECTANGLE_HEIGHT / 2);

    // lower right
    double x2 = RECTANGLE_CENTER.x_ + (RECTANGLE_WIDTH / 2);
    double y2 = RECTANGLE_CENTER.y_ + (RECTANGLE_HEIGHT / 2);

    // converting colors
    Color RECTANGLE_INNER_COLOR = rectangle.get_inner_color();
    ALLEGRO_COLOR RECTANGLE_INNER_COLOR_ALLEGRO = color_convertor(RECTANGLE_INNER_COLOR);
    Color RECTANGLE_OUTER_COLOR = rectangle.get_outer_color();
    ALLEGRO_COLOR RECTANGLE_OUTER_COLOR_ALLEGRO = color_convertor(RECTANGLE_OUTER_COLOR);

    al_draw_filled_rectangle(x1, y1, x2, y2, RECTANGLE_INNER_COLOR_ALLEGRO);
    al_draw_rectangle(x1, y1, x2, y2, RECTANGLE_OUTER_COLOR_ALLEGRO, 2.0);
}

void View::draw(const Circle &circle)
{
    float CIRCLE_X = circle.get_center().x_;
    float CIRCLE_Y = circle.get_center().y_;
    float CIRCLE_RADIUS = circle.get_radius();

    // converting colors
    Color CIRCLE_INNER_COLOR = circle.get_inner_color();
    ALLEGRO_COLOR CIRCLE_INNER_COLOR_ALLEGRO = color_convertor(CIRCLE_INNER_COLOR);
    Color CIRCLE_OUTER_COLOR = circle.get_outer_color();
    ALLEGRO_COLOR CIRCLE_OUTER_COLOR_ALLEGRO = color_convertor(CIRCLE_OUTER_COLOR);

    al_draw_filled_circle(CIRCLE_X, CIRCLE_Y, CIRCLE_RADIUS, CIRCLE_INNER_COLOR_ALLEGRO);
    al_draw_circle(CIRCLE_X, CIRCLE_Y, CIRCLE_RADIUS, CIRCLE_OUTER_COLOR_ALLEGRO, 2.0);
}

void View::draw(Point &center, std::string &text, Color &color)
{
    if (!text.empty())
    {
        const char *c_text = text.c_str();
        ALLEGRO_COLOR allegro_color = color_convertor(color);
        al_draw_text(font_, allegro_color, center.x_, center.y_, ALLEGRO_ALIGN_CENTRE, c_text);
    }
}

ALLEGRO_COLOR View::color_convertor(Color color)
{
    ALLEGRO_COLOR ret;
    switch (color)
    {
    case Color::WHITE:
        ret = COLOR_WHITE;
        break;
    case Color::BLACK:
        ret = COLOR_BLACK;
        break;
    case Color::GREY:
        ret = COLOR_GREY;
        break;
    case Color::RED:
        ret = COLOR_RED;
        break;
    case Color::YELLOW:
        ret = COLOR_YELLOW;
        break;
    case Color::SILVER:
        ret = COLOR_SILVER;
        break;
    case Color::ORANGE:
        ret = COLOR_ORANGE;
        break;
    case Color::CYAN:
        ret = COLOR_CYAN;
        break;
    case Color::GREEN:
        ret = COLOR_GREEN;
        break;
    case Color::MAGENTA:
        ret = COLOR_MAGENTA;
        break;
    case Color::BLUE:
        ret = COLOR_BLUE;
        break;
    case Color::GOLD:
        ret = COLOR_GOLD;
        break;
    case Color::DARK_GOLD:
        ret = COLOR_DARK_GOLD;
        break;
    case Color::NONE:
        ret = COLOR_PINK; // using pink to represent none color
        break;
    default:
        Logger::log("[ERROR] Unknown color");
        break;
    }
    return ret;
}