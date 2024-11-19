#include <iostream>
#include <vector>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_font.h>
#include <allegro5/events.h>


#include "view/window.hpp"
#include "entities/racket.hpp"
#include "entities/brick.hpp"
#include "tests/allegro_test.hpp"


#define FREQUENCY 60

class Game {
    private:
        // Objects
        Window window;
        Racket racket;
        
        // Allegro instances
        ALLEGRO_TIMER* timer;
        ALLEGRO_EVENT event;
        ALLEGRO_EVENT_QUEUE* queue;
        
        // Others
        bool done = false;

    public:
        Game();
        ~Game();
        void runGame();
        void setupGame();
        void cleanUpGame();
        void draw();
        void manageKey(ALLEGRO_EVENT);
        void draw(Racket& racket);
};