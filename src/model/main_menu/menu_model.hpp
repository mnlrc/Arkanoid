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
#define PLAY_BUTTON_TEXT "Play - Enter"
#define LEVEL_BUTTON_TEXT "Select a level - <,>"
#define EXIT_BUTTON_TEXT "Quit Game - Escape"

#include <cmath>
#include <string>

#include "../model.hpp"
#include "../objects/rectangle.hpp"
#include "../objects/text.hpp"
#include "../../global_variables.hpp"
#include "../../log/logger.hpp"

const std::string strings[NUMBER_OF_BUTTONS] = {PLAY_BUTTON_TEXT,
                                                LEVEL_BUTTON_TEXT,
                                                EXIT_BUTTON_TEXT};

class MenuModel : public Model
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

    /**
     * @brief Get the Buttons object
     *
     * @return Rectangle*
     */
    Rectangle *getButtons();

    /**
     * @brief Get the Texts object
     *
     * @return Text*
     */
    Text *getTexts();

    /**
     * @brief Get the inner_color_ attribute
     *
     * @return const Color
     */
    const Color getInnerColor() const noexcept;

    /**
     * @brief Get the outer_color_ attribute
     * 
     * @return const Color 
     */
    const Color getOuterColor() const noexcept;

private:
    Rectangle buttons_[NUMBER_OF_BUTTONS];
    Text texts_[NUMBER_OF_BUTTONS];
    Color inner_color_ = Color::GREY;
    Color outer_color_ = Color::BLACK;
};

#endif