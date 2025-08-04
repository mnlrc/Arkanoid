/**
 * @file controller.cpp
 * @author Manuel Rocca
 * @brief Source file for the Controller class.
 * @date 2025
 */

#include "controller.hpp"

void Controller::setupMenuModel(const int width, const int height)
{
    menu_model = std::make_unique<MenuModel>((width, height));
    current_model = ModelType::MAIN_MENU_MODEL;
}

void Controller::handleKeyInput(int keyCode) {}

void Controller::updateView()
{
    switch (current_model)
    { // call methods from View, should be static (?)
    case ModelType::MAIN_MENU_MODEL:
        break;
    case ModelType::GAME_MODEL:
        break;
    case ModelType::PAUSE_MENU_MODEL:
        break;
    default:
        break;
    }
}