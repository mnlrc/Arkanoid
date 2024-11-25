#include "view.hpp"

View::View(): display(al_create_display(WINDOW_WIDTH, WINDOW_HEIGHT)) {}

View::~View() = default;

ALLEGRO_DISPLAY* View::getDisplay() const noexcept { return display; }

void View::draw(Racket& racket, std::vector<Ball>& balls, std::vector<std::vector<Brick>>& bricks) {
    // Draw the window
    al_draw_filled_rectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, al_map_rgb(0, 0, 255));
    al_draw_rectangle(0, 100, WINDOW_WIDTH, WINDOW_HEIGHT, al_map_rgb(255, 255, 255), 2.0);
    al_draw_rectangle(0, WINDOW_HEIGHT - 500, WINDOW_WIDTH, 0, al_map_rgb(255, 255, 255), 2.0);
     
    drawBall(balls);
    drawBricks(bricks);
    drawRacket(racket);

    al_flip_display();
}

void View::drawBall(std::vector<Ball>& balls) {
    for (auto& ball: balls){
        al_draw_filled_circle(ball.getCenter().x_, ball.getCenter().y_, ball.getRadius(), al_map_rgb(0, 0, 0));
        al_draw_circle(ball.getCenter().x_, ball.getCenter().y_, ball.getRadius(), al_map_rgb(255, 255, 255), 2.0);
    }
};

void View::drawBricks(std::vector<std::vector<Brick>>& bricks) {
    for (auto& bricks_row: bricks) {
        for (auto& brick: bricks_row) {
            float x1 = brick.getCenter().x_ - (brick.getWidth() / 2);
            float x2 = brick.getCenter().x_ + (brick.getWidth() / 2);
            float y1 = brick.getCenter().y_ - (brick.getHeight() / 2);
            float y2 = brick.getCenter().y_ + (brick.getHeight() / 2);
            al_draw_filled_rectangle(x1, y1, x2, y2, al_map_rgb(0, 0, 0));
            al_draw_rectangle(x1, y1, x2, y2, al_map_rgb(255, 255, 255), 2.0);
        }
    }
};

void View::drawRacket(Racket& racket) { 
    float x1 = racket.getCenter().x_ - (racket.getWidth() / 2);
    float x2 = racket.getCenter().x_ + (racket.getWidth() / 2);
    float y1 = racket.getCenter().y_ - (racket.getHeight() / 2);
    float y2 = racket.getCenter().y_ + (racket.getHeight() / 2);
    al_draw_filled_rectangle(x1, y1, x2, y2, al_map_rgb(0, 0, 0));
    al_draw_rectangle(x1, y1, x2, y2, al_map_rgb(255, 255, 255), 2.0);
};