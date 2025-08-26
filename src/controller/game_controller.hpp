/**
 * @file game_controller.hpp
 * @author Manuel Rocca
 * @brief Header file for the GameController class.
 * @date 2025
 */

#ifndef GAME_CONTROLLER_HPP
#define GAME_CONTROLLER_HPP

#include "controller.hpp"
#include "../model/game/engine.hpp"

class Engine;

class GameController : public Controller
{
public:
    /**
     * @brief Construct a new GameController object
     *
     */
    GameController(std::shared_ptr<View> view);

    /**
     * @brief Destroy the GameController object
     *
     */
    ~GameController() = default;

    /**
     * @brief
     *
     */
    bool setup_game_model(short int level);

    /**
     * @brief
     *
     * @param keyCode
     */
    InputResponse handle_key_down(int key_code) override;

    /**
     * @brief
     *
     * @param key_code
     */
    void handle_key_up(int key_code);

    void handle_mouse_movement(ALLEGRO_EVENT mouse_event);

    UpdateResponse update_model();

    void update_view() override;

    void draw_end(bool is_win);

    void reset_game_model() noexcept;

private:
    std::unique_ptr<Engine> engine_;
    std::unique_ptr<GameModel> game_model;

    short int current_level = 0;
    std::unordered_map<Direction, bool> input_keys_ = {{Direction::LEFT, false},
                                                       {Direction::RIGHT, false}};
};

#endif