/**
 * @file game.hpp
 * @author Manuel Rocca
 * @brief Header file for the Game class
 * @date 2025
 *
 */

#ifndef GAME_HPP
#define GAME_HPP

// #### Internal inclusions ####
#include "game_controller.hpp"
#include "menu_controller.hpp"

// #### C++ inclusions ####
#include <map>
#include <memory>

// #### Allegro inclusions ####
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_font.h>
#include <allegro5/events.h>

/**
 * @brief Sets the game up and manages the main loop of the game with allegro
 * tools such as events, the event queue and else.
 *
 */
class Game
{
public:
    /**
     * @brief Construct a new Game object
     *
     */
    Game();

    /**
     * @brief Destroy the Game object
     *
     */
    ~Game();

    /**
     * @brief Runs the whole program loop, manages the switches between menus
     *
     */
    void run();

private:
    std::unique_ptr<GameController> game_controller_;
    std::unique_ptr<MenuController> menu_controller_;

    ALLEGRO_TIMER *timer_;
    ALLEGRO_EVENT event_;
    ALLEGRO_EVENT_QUEUE *queue_;

    // flags corresponding to menus
    bool main_loop = true;
    bool game_loop = false;

    /**
     * @brief Sets up the elements from the allegro library
     *
     * @param view: We add to the view to the event queue
     */
    void setup_allegro(std::shared_ptr<View> view);

    /**
     * @brief Runs the main menu, handles the inputs by popping events from the queue
     *
     */
    void run_main_menu();

    /**
     * @brief Runs the game, handles the inputs by popping events from the queue 
     *
     * @param level: The level to be loaded (given to the GameModel)
     */
    void run_game(short level);

    /**
     * @brief Handles the response received from the Model via the Controller
     * 
     * @param response: The response's value
     * @param done: The flag of the loop (by reference so we can update it)
     */
    void handle_input_response(InputResponse response, bool &done);

    /**
     * @brief Handles the update responses received from the GameModel after each tic
     * 
     * @param response: The value of the response
     * @return true: If the game's finished (win or lose)
     * @return false: If the game continues
     */
    bool handle_update_response(UpdateResponse response);
};

#endif