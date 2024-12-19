/**
 * @file view.cpp
 * @author Manuel Rocca
 * @brief Source file for the View class
 * @date 2024
 *
 */

#include "view.hpp"

View::View() {
    init_test(al_init(), "allegro");
    display_ = al_create_display(WINDOW_WIDTH, WINDOW_HEIGHT);
    init_test(display_, "display");
    init_test(al_init_primitives_addon(), "primitives");
}

View::~View() { al_destroy_display(display_); };

ALLEGRO_DISPLAY* View::getDisplay() const noexcept { return display_; }

void View::drawAll(const Racket& racket, const std::vector<Ball>& balls, const std::vector<std::vector<Brick>>& bricks) {
    // Draw the window
    al_draw_filled_rectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, COLOR_DARK_GREY); // background
    al_draw_rectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, COLOR_WHITE, 4.0); // game border
     
    drawBall(balls);
    drawBricks(bricks);
    drawRacket(racket);

    al_flip_display();
}

void View::drawBall(const std::vector<Ball>& balls) {
    for (auto& ball: balls){
        al_draw_filled_circle(ball.getCenter().x_, ball.getCenter().y_, ball.getRadius(), al_map_rgb(0, 0, 0));
        al_draw_circle(ball.getCenter().x_, ball.getCenter().y_, ball.getRadius(), al_map_rgb(255, 255, 255), 2.0);
    }
};

void View::drawBricks(const std::vector<std::vector<Brick>>& bricks) {
    for (auto& bricks_row: bricks) {
        for (auto& brick: bricks_row) {
            if (!brick.isBroken()) {
                float x1 = brick.getCenter().x_ - (brick.getWidth() / 2);
                float x2 = brick.getCenter().x_ + (brick.getWidth() / 2);
                float y1 = brick.getCenter().y_ - (brick.getHeight() / 2);
                float y2 = brick.getCenter().y_ + (brick.getHeight() / 2);
                al_draw_filled_rectangle(x1, y1, x2, y2, al_map_rgb(0, 0, 0));
                al_draw_rectangle(x1, y1, x2, y2, al_map_rgb(255, 255, 255), 2.0);
            }
        }
    }
};

void View::drawRacket(const Racket& racket) { 
    float x1 = racket.getCenter().x_ - (racket.getWidth() / 2);
    float x2 = racket.getCenter().x_ + (racket.getWidth() / 2);
    float y1 = racket.getCenter().y_ - (racket.getHeight() / 2);
    float y2 = racket.getCenter().y_ + (racket.getHeight() / 2);
    al_draw_filled_rectangle(x1, y1, x2, y2, al_map_rgb(0, 0, 0));
    al_draw_rectangle(x1, y1, x2, y2, al_map_rgb(255, 255, 255), 2.0);
};


// Optional modularity
void View::draw(const Racket& racket) {
    drawRacket(racket);
}

void View::draw(const std::vector<Ball>& balls) {
    drawBall(balls);
}

void View::draw(const std::vector<std::vector<Brick>>& bricks) {
    drawBricks(bricks);
}