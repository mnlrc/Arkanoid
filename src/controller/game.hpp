/**
 * @file game.hpp
 * @author Manuel Rocca
 * @brief Header file for the Game class
 * @date 2024
 *
 */

#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <map>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_font.h>
#include <allegro5/events.h>


#include "../view/view.hpp"
#include "../entities/score.hpp"
#include "control.hpp"

#define FREQUENCY 60
#define BRICKS_COLS 14 // number of brick columns
#define BRICKS_ROWS 8 // number of brick rows


class Game {
    private:
        // #### Objects ####
        View gameView_;
        Racket racket_;
        std::vector<Ball> balls_;
        std::vector<std::vector<Brick>> bricks_;
        Score score_;
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
        Game();

        // #### Destructor ####
        ~Game();

        // #### Public methods ####
        void runGame();
        void update();
};

#endif
