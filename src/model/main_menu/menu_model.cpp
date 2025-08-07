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
    double shift_percentage = 0.2;           // 20%
    double width_percentage = 0.8;           // 80%
    double button_height = height_ * 1 / 10; // 10% of the height
    double button_width = width * width_percentage;
    double button_shift = height_ * shift_percentage;
    double button_starting_pos = model_middle.y_ - button_shift;

    for (size_t i = 0; i < NUMBER_OF_BUTTONS; i++)
    {
        Point center{static_cast<double>(width / 2), button_starting_pos};
        std::vector<Text> button_texts;

        switch (i)
        {
        case 0:
            button_texts.emplace_back(PLAY_BUTTON_TEXT, Color::WHITE, center);
            break;
        case 1:
            for (const std::string &s : LEVEL_BUTTON_TEXT)
                button_texts.emplace_back(s, Color::WHITE, center);
            break;
        case 2:
            button_texts.emplace_back(EXIT_BUTTON_TEXT, Color::WHITE, center);
            break;
        default:
            Logger::log("[ERROR] Unknown");
            break;
        }

        buttons_.emplace_back(Button(button_texts, center, button_width, button_height));
        button_starting_pos += button_shift;
    }
}

std::vector<Button> MenuModel::getButtons() { return buttons_; }

const Color MenuModel::getInnerColor() const noexcept { return inner_color_; }

const Color MenuModel::getOuterColor() const noexcept { return outer_color_; }

void MenuModel::cycleText(bool next) {
    size_t level_text_idx = 1;
    if (next) {
        buttons_[level_text_idx].nextText();
    }
    else if (!next) {
        buttons_[level_text_idx].previousText();
    }
}