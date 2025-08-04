/**
 * @file game.hpp
 * @author Manuel Rocca
 * @brief Header file for the Game class
 * @date 2024
 *
 */

#ifndef GAME_HPP
#define GAME_HPP

#define MAIN_MENU_WIDTH 600
#define MAIN_MENU_HEIGHT 700

#define FREQUENCY 60
#define BRICKS_COLS 14 // number of brick columns
#define BRICKS_ROWS 8  // number of brick rows

#include <iostream>
#include <map>
#include <memory>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_font.h>
#include <allegro5/events.h>

#include "../view/view.hpp"
#include "controller.hpp"

/**
 * @brief Sets the game up and manages the main loop of the game with allegro
 * tools such as events, the event queue and else.
 *
 */
class Game
{
public:
    // #### Constructor ####
    /**
     * @brief Construct a new Game object
     *
     */
    Game();

    // #### Destructor ####
    /**
     * @brief Destroy the Game object
     *
     */
    ~Game();

    // #### Public methods ####
    void run();
    // void update();

private:
    // #### Objects ####
    View view_;
    Controller controller_;

    // TODO: déplacer dans le controller
    // Racket racket_;
    // std::vector<Ball> balls_;
    // std::vector<std::vector<Brick>> bricks_;
    // Score score_;

    // #### Allegro instances ####
    ALLEGRO_TIMER *timer_;
    ALLEGRO_EVENT event_;
    ALLEGRO_EVENT_QUEUE *queue_;

    // #### Others ####
    bool main_loop = true;
    bool game_loop = false;
    bool pause_loop = false;
    // std::map<std::string, bool> inputKeys_ = {{"left", false}, {"right", false}};

    // #### Private methods ####
    // void manageKeyDown(ALLEGRO_EVENT);
    // void manageKeyUp(ALLEGRO_EVENT);

    /**
     * @brief
     *
     * @param model
     */
    void setupModel(ModelType model);

    /**
     * @brief
     *
     */
    void setupAllegro();

    /**
     * @brief
     *
     */
    void runMainMenu();

    /**
     * @brief
     *
     */
    void runGame();

    /**
     * @brief
     *
     */
    void runPauseMenu();
};

#endif
