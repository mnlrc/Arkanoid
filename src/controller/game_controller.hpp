/**
 * @file game_controller.hpp
 * @author Manuel Rocca
 * @brief Header file for the GameController class.
 * @date 2025
 */

#ifndef GAME_CONTROLLER_HPP
#define GAME_CONTROLLER_HPP

// #### Internal inclusions ####
#include "controller.hpp"
#include "../model/game/engine.hpp"
#include "../model/objects/score_manager.hpp"

class Engine;

/**
 * @brief GameController handles the game.
 * It handles the inputs, updates and sets up the Models, updates the view, ...
 *
 */
class GameController final : public Controller
{
public:
    /**
     * @brief Construct a new Game Controller object
     *
     * @param view: The view to update
     */
    GameController(std::shared_ptr<View> view);

    /**
     * @brief Sets up a new GameModel (level)
     *
     * @param level: The level to load
     *
     * @return bool: True if the Model was successfully loaded, false otherwise
     */
    bool setup_game_model(short int level);

    /**
     * @brief Handles the ALLEGRO_KEY_DOWN event by calling the right functions
     * based on the key_code
     *
     * @param key_code: The key code of the event
     *
     * @return InputResponse: A response to the input that signals any internal change in the Model
     */
    InputResponse handle_key_down(int key_code) override;

    /**
     * @brief Handles the ALLEGRO_KEY_UP event by calling the right functions
     * based on the key_code
     *
     * @param key_code: The key code of the event
     */
    void handle_key_up(int key_code) override;

    /**
     * @brief Handles the ALLEGRO_EVENT_MOUSE_AXES event by calling the right functions
     *
     * @param mouse_event: The event itself that holds the position of the mouse
     */
    void handle_mouse_movement(ALLEGRO_EVENT mouse_event);

    /**
     * @brief Updates/refreshes the model after each tic, each ALLEGRO_TIMER_EVENT
     *
     * @return UpdateResponse: The Model gives a response corresponding to the state of the game
     * and how to continue
     */
    UpdateResponse update_model();

    /**
     * @brief Updates the view by drawing the updated Model
     *
     */
    void update_view() override;

    /**
     * @brief Draws the end button
     *
     * @param is_win: Determines wether to draw the win or the lose button
     */
    void draw_end(bool is_win);

    /**
     * @brief Resets the GameModel unique_ptr
     *
     */
    void reset_game_model() noexcept;

    /**
     * @brief Updates the high score by calling the static methods of the ScoreManager
     *
     */
    void update_score() const noexcept;

private:
    std::unique_ptr<Engine> engine_;
    std::unique_ptr<GameModel> game_model;

    short int current_level = 0; // the currently selected level, 0 means None
    // directions to know in which direction to move the racket if a key is held
    std::unordered_map<Direction, bool> input_keys_ = {{Direction::LEFT, false},
                                                       {Direction::RIGHT, false}};
};

#endif