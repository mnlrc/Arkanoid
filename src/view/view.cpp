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
    // init_test(al_init_ttf_addon(), "TTF addon");
    init_test(display_, "display");
}

ALLEGRO_DISPLAY *View::getDisplay() const noexcept { return display_; }

void View::draw(const std::unique_ptr<MenuModel> &model)
{
    // drawing main window
    const int window_width = model->getWidth();
    const int window_height = model->getHeight();
    const Color temp_inner_color = model->getInnerColor();
    const Color temp_outer_color = model->getOuterColor();

    ALLEGRO_COLOR window_inner_color = colorConvertor(temp_inner_color);
    ALLEGRO_COLOR window_outer_color = colorConvertor(temp_outer_color);

    al_draw_filled_rectangle(0, 0, window_width, window_height, window_inner_color);
    al_draw_rectangle(0, 0, window_width, window_height, window_outer_color, 4.0);

    // drawing it's contents
    const Rectangle *buttons_ = model->getButtons();
    const Text *texts_ = model->getTexts();
    for (size_t i = 0; i < NUMBER_OF_BUTTONS; i++)
    {
        Rectangle temp_rec = buttons_[i];

        Point rec_center = temp_rec.getCenter();
        double rec_width = temp_rec.getWidth();
        double rec_height = temp_rec.getHeight();

        // upper left
        double x1 = rec_center.x_ - (rec_width / 2);
        double y1 = rec_center.y_ - (rec_height / 2);

        // lower right
        double x2 = rec_center.x_ + (rec_width / 2);
        double y2 = rec_center.y_ + (rec_height / 2);

        al_draw_filled_rectangle(x1, y1, x2, y2, COLOR_BLACK);

        Text temp_text = texts_[i];
    }

    al_flip_display();
}

// void View::drawAll(const Racket &racket, const std::vector<Ball> &balls, const std::vector<std::vector<Brick>> &bricks)
// {
//     // Draw the window
//     al_draw_filled_rectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, COLOR_DARK_GREY); // background
//     al_draw_rectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, COLOR_WHITE, 4.0);       // game border

//     drawBall(balls);
//     drawBricks(bricks);
//     drawRacket(racket);

//     al_flip_display();
// }

// void View::drawBall(const std::vector<Ball> &balls)
// {
//     for (auto &ball : balls)
//     {
//         al_draw_filled_circle(ball.getCenter().x_, ball.getCenter().y_, ball.getRadius(), al_map_rgb(0, 0, 0));
//         al_draw_circle(ball.getCenter().x_, ball.getCenter().y_, ball.getRadius(), al_map_rgb(255, 255, 255), 2.0);
//     }
// };

// void View::drawBricks(const std::vector<std::vector<Brick>> &bricks)
// {
//     for (auto &bricks_row : bricks)
//     {
//         for (auto &brick : bricks_row)
//         {
//             if (!brick.isBroken())
//             {
//                 float x1 = brick.getCenter().x_ - (brick.getWidth() / 2);
//                 float x2 = brick.getCenter().x_ + (brick.getWidth() / 2);
//                 float y1 = brick.getCenter().y_ - (brick.getHeight() / 2);
//                 float y2 = brick.getCenter().y_ + (brick.getHeight() / 2);
//                 al_draw_filled_rectangle(x1, y1, x2, y2, al_map_rgb(0, 0, 0));
//                 al_draw_rectangle(x1, y1, x2, y2, al_map_rgb(255, 255, 255), 2.0);
//             }
//         }
//     }
// };

// void View::drawRacket(const Racket &racket)
// {
//     float x1 = racket.getCenter().x_ - (racket.getWidth() / 2);
//     float x2 = racket.getCenter().x_ + (racket.getWidth() / 2);
//     float y1 = racket.getCenter().y_ - (racket.getHeight() / 2);
//     float y2 = racket.getCenter().y_ + (racket.getHeight() / 2);
//     al_draw_filled_rectangle(x1, y1, x2, y2, al_map_rgb(0, 0, 0));
//     al_draw_rectangle(x1, y1, x2, y2, al_map_rgb(255, 255, 255), 2.0);
// };

// // Optional modularity
// void View::draw(const Racket &racket)
// {
//     drawRacket(racket);
// }

// void View::draw(const std::vector<Ball> &balls)
// {
//     drawBall(balls);
// }

// void View::draw(const std::vector<std::vector<Brick>> &bricks)
// {
//     drawBricks(bricks);
// }

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
    default:
        Logger::log("[ERROR] Unknown color");
        break;
    }
    return ret;
}
