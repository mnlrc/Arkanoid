/**
 * @file game_controller.cpp
 * @author Manuel Rocca
 * @brief Source file for the GameController class.
 * @date 2025
 */

#include "game_controller.hpp"

GameController::GameController(std::shared_ptr<View> view) : Controller{view} {}

bool GameController::setup_game_model(short int level)
{
    if (level != current_level)
    {
        reset_game_model();
        try
        {
            game_model = std::make_unique<GameModel>(level);
            current_level = level;
        }
        catch (const std::exception &e)
        {
            Logger::log(std::string("[ERROR] Exception while creating GameModel: ") + e.what());
            return false;
        }
    }
    return true;
}

InputResponse GameController::handle_key_down(int key_code)
{
    switch (key_code)
    {
    case ALLEGRO_KEY_A:
    case ALLEGRO_KEY_Q:
    case ALLEGRO_KEY_LEFT:
        input_keys_[Direction::LEFT] = true;
        return InputResponse::NONE;
    case ALLEGRO_KEY_D:
    case ALLEGRO_KEY_P:
    case ALLEGRO_KEY_RIGHT:
        input_keys_[Direction::RIGHT] = true;
        return InputResponse::NONE;
    case ALLEGRO_KEY_SPACE: // launch a ball or shoot a laser
        game_model->handle_space_input();
        return InputResponse::NONE;
    case ALLEGRO_KEY_ESCAPE: // return to previous menu
        return InputResponse::QUIT;
    default:
        Logger::log("[ERROR] Invalid input");
        return InputResponse::NONE;
    }
}

void GameController::handle_key_up(int key_code)
{
    switch (key_code)
    {
    case ALLEGRO_KEY_A:
    case ALLEGRO_KEY_Q:
    case ALLEGRO_KEY_LEFT:
        input_keys_[Direction::LEFT] = false;
    case ALLEGRO_KEY_D:
    case ALLEGRO_KEY_P:
    case ALLEGRO_KEY_RIGHT:
        input_keys_[Direction::RIGHT] = false;
    }
}

UpdateResponse GameController::update_model()
{
    if (input_keys_[Direction::RIGHT])
    {
        engine_->move(game_model->get_racket(), Direction::RIGHT);
    }

    else if (input_keys_[Direction::LEFT])
    {
        engine_->move(game_model->get_racket(), Direction::LEFT);
    }

    return engine_->update_model(*game_model);
}

void GameController::update_view()
{
    view_->render_game_model(game_model);
}

void GameController::draw_end(bool is_win)
{
    Button end_button = game_model->get_end_button(is_win);
    view_->render_button(end_button);
}

void GameController::reset_game_model() noexcept
{
    if (game_model)
    {
        game_model.reset();
        current_level = 0;
    }
}