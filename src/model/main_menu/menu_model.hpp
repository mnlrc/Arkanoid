/**
 * @file menu_model.cpp
 * @author Manuel Rocca
 * @brief Source file for the MenuModel class
 * @date 2025
 *
 */

#ifndef MENU_MODEL_HPP
#define MENU_MODEL_HPP

#define NUMBER_OF_BUTTONS 3
#define PLAY_BUTTON_TEXT "Play"
#define LEVEL_BUTTON_TEXT "Select a level"
#define EXIT_BUTTON_TEXT "Quit Game"

#include <cmath>
#include <string>

#include "../model.hpp"
#include "../objects/rectangle.hpp"
#include "../objects/text.hpp"

const std::string strings[NUMBER_OF_BUTTONS] = {PLAY_BUTTON_TEXT,
                                                LEVEL_BUTTON_TEXT,
                                                EXIT_BUTTON_TEXT};

class MenuModel : Model
{
public:
    /**
     * @brief Construct a new Menu Model object
     *
     * @param width The width of the model's window
     * @param height The height of the model's window
     */
    MenuModel(const int width, const int height);

    /**
     * @brief Destroy the Menu Model object
     *
     */
    ~MenuModel() = default;

private:
    Rectangle buttons_[NUMBER_OF_BUTTONS];
    Text texts_[NUMBER_OF_BUTTONS];
};

#endif