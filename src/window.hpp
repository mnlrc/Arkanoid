#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include "allegro_test.hpp"

#define WIDTH 500
#define HEIGHT 600

class Window {
    
    private:
        ALLEGRO_DISPLAY* display;
        // A VOIR POUR CENTRER
        // int monitor_index;
        // ALLEGRO_MONITOR_INFO monitor_info;
    public:
        Window();
        void center_window();
        ALLEGRO_DISPLAY* getDisplay() const noexcept;
        void draw_game_limits();
};