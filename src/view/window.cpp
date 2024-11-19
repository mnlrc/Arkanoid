#include "window.hpp"

Window::Window() {
    // Initializing ALLEGRO_DISPLAY
    display = al_create_display(WIDTH, HEIGHT);
    init_test(display, "display");
}

ALLEGRO_DISPLAY* Window::getDisplay() const noexcept { return display; }

void Window::center_window(){  
    // Calculating postions
    int x_pos = (1920 - WIDTH) / 2;
    int y_pos = (1080 - HEIGHT) / 2;
    // Centering window
    al_set_window_position(display, x_pos, y_pos);
}

void Window::draw_game_limits(){
    al_draw_rectangle(0, 100, WIDTH, HEIGHT, al_map_rgb(255, 255, 255), 2.0);
    al_draw_rectangle(0, HEIGHT - 500, WIDTH, 0, al_map_rgb(255, 255, 255), 2.0);
}