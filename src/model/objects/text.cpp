/**
 * @file text.cpp
 * @author Manuel Rocca
 * @brief Source file for the Text class
 * @date 2025
 *
 */

#include "text.hpp"

Text::Text(std::string str, Color color) : text_(str), color_(color) {}

Color Text::get_color() const noexcept { return color_; }

std::string Text::get_text() const noexcept { return text_; }