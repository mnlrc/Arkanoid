#include <iostream>
#include <map>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_font.h>
#include <allegro5/events.h>


#include "view/view.hpp"
#include "control.hpp"

#define FREQUENCY 60
#define BRICKS_COLS 14 // number of brick columns
#define BRICKS_ROWS 8 // number of brick rows

const int KEY_LEFT = ALLEGRO_KEY_Q;
const int KEY_RIGHT = ALLEGRO_KEY_D;
const int KEY_SPACE = ALLEGRO_KEY_SPACE;

class Game {
    private:
        // #### Objects ####
        View gameView_;
        Racket racket_;
        std::vector<Ball> balls_;
        std::vector<std::vector<Brick>> bricks_;
        Control control_;
        
        // #### Allegro instances ####
        ALLEGRO_TIMER* timer_;
        ALLEGRO_EVENT event_;
        ALLEGRO_EVENT_QUEUE* queue_;
        
        // #### Others ####
        bool done = false;
        bool yes = false;
        std::map<std::string, bool> inputKeys_ = {{"left", false}, {"right", false}};

        // #### Private methods ####
        void manageKeyDown(ALLEGRO_EVENT);
        void manageKeyUp(ALLEGRO_EVENT);
        void setupGame();

    public:
        // #### Constructor ####
        Game(View gameview);

        // #### Destructor ####
        ~Game();

        // #### Public methods ####
        void runGame();
        void update();
};