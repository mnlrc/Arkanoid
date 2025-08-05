/**
 * @file menu_model.cpp
 * @author Manuel Rocca
 * @brief Source file for the MenuModel class
 * @date 2025
 *
 */

#include "menu_model.hpp"

MenuModel::MenuModel(const int width, const int height) : Model{width, height}
{
    Point model_middle = Point{static_cast<double>(width_ / 2), static_cast<double>(height_ / 2)};
    double shift_percentage = 25 / 100;      // 25%
    double button_height = height_ * 1 / 10; // 10% of the height
    double button_shift = height_ * shift_percentage;

    double button_starting_pos = model_middle.y_ + button_shift;
    for (size_t i = 0; i < NUMBER_OF_BUTTONS; i++)
    {
        buttons_[i] = Rectangle(Point{static_cast<double>(width_ / 2),
                                      button_starting_pos},
                                width_,
                                button_height);
        button_starting_pos = button_starting_pos - button_shift;

        texts_[i] = Text(strings[i],
                         Color::WHITE,
                         Point{static_cast<double>(width_ / 2),
                               button_starting_pos});
    }
}

Rectangle *MenuModel::getButtons() { return buttons_; }

Text *MenuModel::getTexts() { return texts_; }

const Color MenuModel::getInnerColor() const noexcept { return inner_color_; }

const Color MenuModel::getOuterColor() const noexcept { return outer_color_; }
