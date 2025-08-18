/**
 * @file controller.cpp
 * @author Manuel Rocca
 * @brief Source file for the Controller class.
 * @date 2025
 */

#include "controller.hpp"

void Controller::initView()
{
    view_ = std::make_unique<View>(WINDOW_WIDTH, WINDOW_HEIGHT);
}

void Controller::setupMenuModel(const int width, const int height)
{
    menu_model = std::make_unique<MenuModel>(width, height);
    current_model = ModelType::MAIN_MENU_MODEL;
}

void Controller::setupGameModel()
{
    int level = menu_model->get_selected_level();
    game_model = std::make_unique<GameModel>(level);
    current_model = ModelType::GAME_MODEL;
}

Input_response Controller::handleKeyInput(int key_code)
{
    switch (current_model)
    {
    case ModelType::MAIN_MENU_MODEL:
        return handle_menu_input(key_code);
    case ModelType::GAME_MODEL:
        return handle_game_input(key_code);
    default:
        Logger::log("[ERROR] Unknown Model Type");
        return Input_response::NONE;
    }
}

void Controller::updateView()
{
    switch (current_model)
    {
    case ModelType::MAIN_MENU_MODEL:
        view_->draw(menu_model);
        break;
    case ModelType::GAME_MODEL:
        view_->draw(game_model);
        break;
    case ModelType::PAUSE_MENU_MODEL:
        break;
    default:
        break;
    }
}

ALLEGRO_DISPLAY *Controller::getDisplay() const noexcept { return view_->getDisplay(); }

void Controller::swap_model()
{
    if (current_model == ModelType::MAIN_MENU_MODEL)
    {
        current_model = ModelType::GAME_MODEL;
    }
    if (current_model == ModelType::GAME_MODEL)
    {
        current_model = ModelType::MAIN_MENU_MODEL;
    }
}

Input_response Controller::handle_menu_input(int key_code)
{
    switch (key_code)
    {
    case ALLEGRO_KEY_ESCAPE:
        return Input_response::QUIT;
    case ALLEGRO_KEY_ENTER:
        return Input_response::ENTER;
    case ALLEGRO_KEY_LEFT:
        menu_model->cycleText(false);
        return Input_response::NONE;
    case ALLEGRO_KEY_RIGHT:
        menu_model->cycleText(true);
        return Input_response::NONE;
    default:
        Logger::log("[ERROR] Invalid input");
        return Input_response::NONE;
    }
}

Input_response Controller::handle_game_input(int key_code)
{
    switch (key_code)
    {
    case ALLEGRO_KEY_LEFT:
        return Input_response::NONE;
    case ALLEGRO_KEY_RIGHT:
        return Input_response::NONE;
    case ALLEGRO_KEY_SPACE: // starting the game OR throwing the ball
        return Input_response::NONE;
    case ALLEGRO_KEY_ESCAPE: // return to previous menu
        swap_model();
        return Input_response::QUIT;
    default:
        Logger::log("[ERROR] Invalid input");
        return Input_response::NONE;
    }
}