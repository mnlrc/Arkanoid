#include "window.hpp"
#include "allegro_test.hpp"

Window::Window() : width(500), height(500) {

    // Initializing ALLEGRO_DISPLAY
    display = al_create_display(width, height);
    init_test(display, "display");

    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_flip_display();  // Update display
}

ALLEGRO_DISPLAY* Window::getDisplay() const noexcept { return display; }