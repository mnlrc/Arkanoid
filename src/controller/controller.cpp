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

void Controller::handleKeyInput(int keyCode)
{
    switch (keyCode)
    {
    case ALLEGRO_KEY_LEFT:
        menu_model->cycleText(false);
        break;
    case ALLEGRO_KEY_RIGHT:
        menu_model->cycleText(true);
        break;
    default:
        Logger::log("[ERROR] Invalid input");
        break;
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
        game_model.release();
    }
}