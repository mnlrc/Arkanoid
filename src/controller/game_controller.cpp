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
        game_model.release();
        try
        {
            game_model = std::make_unique<GameModel>(level);
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
    case ALLEGRO_KEY_SPACE: // starting the game OR throwing the ball
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

void GameController::update_model()
{
    if (input_keys_[Direction::RIGHT])
    {
        engine_->move(*game_model->get_racket(), Direction::RIGHT);
    }

    else if (input_keys_[Direction::LEFT])
    {
        engine_->move(*game_model->get_racket(), Direction::LEFT);
    }

    // TODO: move ball
    // engine_->move(ball);
}

void GameController::update_view()
{
    view_->draw(game_model);
}
