/**
 * @file game.hpp
 * @author Manuel Rocca
 * @brief Header file for the Game class
 * @date 2024
 *
 */

#ifndef GAME_HPP
#define GAME_HPP

#define FREQUENCY 60
#define BRICKS_COLS 14 // number of brick columns
#define BRICKS_ROWS 8  // number of brick rows

#include <map>
#include <memory>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_font.h>
#include <allegro5/events.h>

#include "game_controller.hpp"
#include "menu_controller.hpp"

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
    std::unique_ptr<GameController> game_controller_;
    std::unique_ptr<MenuController> menu_controller_;

    // #### Allegro instances ####
    ALLEGRO_TIMER *timer_;
    ALLEGRO_EVENT event_;
    ALLEGRO_EVENT_QUEUE *queue_;

    // #### Others ####
    bool main_loop = true;
    bool game_loop = false;

    // #### Private methods ####
    /**
     * @brief
     *
     */
    void setup_allegro(std::shared_ptr<View> view);

    /**
     * @brief
     *
     */
    void run_main_menu();

    /**
     * @brief
     *
     */
    void run_game(short level);

    void handle_input_response(InputResponse response, bool &done);

    bool handle_update_response(UpdateResponse response);
};

#endif