#include <iostream>
#include <array>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_font.h>
#include <allegro5/events.h>


#include "view/view.hpp"


#define FREQUENCY 60
#define NUMBER_OF_BRICKS 78 // By counting the ones on the example given in the instructions

class Game {
    private:
        // Objects
        View gameView;
        Racket racket;
        Ball ball;
        Brick bricks[NUMBER_OF_BRICKS];
        
        // Allegro instances
        ALLEGRO_TIMER* timer;
        ALLEGRO_EVENT event;
        ALLEGRO_EVENT_QUEUE* queue;
        
        // Others
        bool done = false;

        // Private methods
        void cleanUpGame();
        void manageKey(ALLEGRO_EVENT);

    public:
        Game();
        ~Game();
        void runGame();
        void setupGame();
};