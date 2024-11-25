#include <iostream>
#include <array>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_font.h>
#include <allegro5/events.h>


#include "view/view.hpp"


#define FREQUENCY 60
#define BRICKS_COLS 14 // number of brick columns
#define BRICKS_ROWS 8 // number of brick rows

class Game {
    private:
        // Objects
        View gameView_;
        Racket racket_;
        std::vector<Ball> balls_;
        std::vector<std::vector<Brick>> bricks_;
        
        // Allegro instances
        ALLEGRO_TIMER* timer_;
        ALLEGRO_EVENT event_;
        ALLEGRO_EVENT_QUEUE* queue_;
        
        // Others
        bool done = false;

        // Private methods
        void cleanUpGame();
        void manageKey(ALLEGRO_EVENT);
        void setupGame();

    public:
        Game();
        ~Game();
        void runGame();
        void update();
};