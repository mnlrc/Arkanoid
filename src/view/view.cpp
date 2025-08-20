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

ALLEGRO_DISPLAY *View::getDisplay() const noexcept { return display_; }

void View::draw(const std::unique_ptr<MenuModel> &model)
{
    draw_window(*model);

    std::vector<Button> buttons = model->getButtons();

    for (size_t i = 0; i < NUMBER_OF_BUTTONS; i++)
    {
        Rectangle temp_rec = buttons[i].getRectangle();

        Point rec_center = temp_rec.get_center();
        double rec_width = temp_rec.get_width();
        double rec_height = temp_rec.get_height();

        // upper left
        double x1 = rec_center.x_ - (rec_width / 2);
        double y1 = rec_center.y_ - (rec_height / 2);

        // lower right
        double x2 = rec_center.x_ + (rec_width / 2);
        double y2 = rec_center.y_ + (rec_height / 2);

        Color temp_inner_color = temp_rec.get_inner_color();
        ALLEGRO_COLOR temp_inner_allegro_color = colorConvertor(temp_inner_color);
        Color temp_outer_color = temp_rec.get_outer_color();
        ALLEGRO_COLOR temp_outer_allegro_color = colorConvertor(temp_outer_color);

        al_draw_filled_rectangle(x1, y1, x2, y2, temp_inner_allegro_color);
        al_draw_rectangle(x1, y1, x2, y2, temp_outer_allegro_color, 2.0);

        Text temp_text = buttons[i].getSelectedText();

        Point text_center = rec_center;
        std::string temp_string = temp_text.get_text();
        Color temp_color = temp_text.get_color();

        const char *text = temp_string.c_str();
        ALLEGRO_COLOR text_color = colorConvertor(temp_color);

        al_draw_text(font_, text_color, text_center.x_, text_center.y_, ALLEGRO_ALIGN_CENTRE, text);
    }

    al_flip_display();
}

void View::draw(const std::unique_ptr<GameModel> &game_model)
{
    draw_window(*game_model);

    std::shared_ptr<Racket> temp_racket = game_model->get_racket();
    Color racket_inner_color = temp_racket->get_inner_color();
    ALLEGRO_COLOR racket_inner_allegro_color = colorConvertor(racket_inner_color);
    Color racket_outer_color = temp_racket->get_outer_color();
    ALLEGRO_COLOR racket_outer_allegro_color = colorConvertor(racket_outer_color);
    float x1 = temp_racket->get_center().x_ - (temp_racket->get_width() / 2);
    float x2 = temp_racket->get_center().x_ + (temp_racket->get_width() / 2);
    float y1 = temp_racket->get_center().y_ - (temp_racket->get_height() / 2);
    float y2 = temp_racket->get_center().y_ + (temp_racket->get_height() / 2);
    al_draw_filled_rectangle(x1, y1, x2, y2, racket_inner_allegro_color);
    al_draw_rectangle(x1, y1, x2, y2, racket_outer_allegro_color, 2.0);

    std::vector<std::shared_ptr<Ball>> temp_balls = game_model->get_balls();
    for (auto &ball : temp_balls)
    {
        al_draw_filled_circle(ball->get_center().x_, ball->get_center().y_, ball->get_radius(), al_map_rgb(0, 0, 0));
        al_draw_circle(ball->get_center().x_, ball->get_center().y_, ball->get_radius(), al_map_rgb(255, 255, 255), 2.0);
    }

    std::vector<std::vector<std::shared_ptr<Brick>>> temp_bricks = game_model->get_bricks();

    for (auto &bricks_row : temp_bricks)
    {
        for (auto &brick : bricks_row)
        {
            if (!brick->is_broken())
            {
                Color brick_inner_color = brick->get_inner_color();
                ALLEGRO_COLOR brick_inner_allegro_color = colorConvertor(brick_inner_color);
                Color brick_outer_color = brick->get_outer_color();
                ALLEGRO_COLOR brick_outer_allegro_color = colorConvertor(brick_outer_color);
                float x1 = brick->get_center().x_ - (brick->get_width() / 2);
                float x2 = brick->get_center().x_ + (brick->get_width() / 2);
                float y1 = brick->get_center().y_ - (brick->get_height() / 2);
                float y2 = brick->get_center().y_ + (brick->get_height() / 2);
                al_draw_filled_rectangle(x1, y1, x2, y2, brick_inner_allegro_color);
                al_draw_rectangle(x1, y1, x2, y2, brick_outer_allegro_color, 2.0);
            }
        }
    }
    al_flip_display();
}

ALLEGRO_COLOR View::colorConvertor(Color color)
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
    default:
        Logger::log("[ERROR] Unknown color");
        break;
    }
    return ret;
}

void View::draw_window(const Model &model)
{
    // drawing main window
    const int window_width = model.getWidth();
    const int window_height = model.getHeight();
    const Color temp_inner_color = model.getInnerColor();
    const Color temp_outer_color = model.getOuterColor();

    ALLEGRO_COLOR window_inner_color = colorConvertor(temp_inner_color);
    ALLEGRO_COLOR window_outer_color = colorConvertor(temp_outer_color);

    al_draw_filled_rectangle(0, 0, window_width, window_height, window_inner_color);
    al_draw_rectangle(0, 0, window_width, window_height, window_outer_color, 4.0);
}