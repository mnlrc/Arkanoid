#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <iostream>

#include "window.hpp"

class Game {
    private:
        Window window;
    public:
        Game();
        void runGame();
};