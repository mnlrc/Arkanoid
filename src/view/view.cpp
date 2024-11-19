#include "view.hpp"

View::View(): display(al_create_display(WINDOW_WIDTH, WINDOW_HEIGHT)) {

};

View::~View() {};

ALLEGRO_DISPLAY* View::getDisplay() const noexcept { return display; }

void View::draw() { 
    drawBall();
    drawRacket();
    drawRacket();
}

void View::drawBall() {};

void View::drawBricks() {};

void View::drawRacket() {};

// void Window::draw_game_limits(){
//     al_draw_rectangle(0, 100, WIDTH, HEIGHT, al_map_rgb(255, 255, 255), 2.0);
//     al_draw_rectangle(0, HEIGHT - 500, WIDTH, 0, al_map_rgb(255, 255, 255), 2.0);
// }