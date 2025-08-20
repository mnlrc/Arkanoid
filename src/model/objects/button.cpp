/**
 * @file button.cpp
 * @author Manuel Rocca
 * @brief Source file for the Button class
 * @date 2025
 *
 */

#include "button.hpp"

Button::Button(const std::vector<Text> &texts, Point &center, double width, double height, Color inner_color, Color outer_color)
    : texts_(texts), idx_(0), rectangle_(Rectangle{center, width, height, inner_color, outer_color}) {}

const Text &Button::getSelectedText() const noexcept { return texts_[idx_]; }

void Button::nextText()
{
    if (texts_.size() > 1)
        idx_ = (idx_ + 1) % texts_.size();
}

void Button::previousText()
{
    if (texts_.size() > 1)
        idx_ = (idx_ + texts_.size() - 1) % texts_.size();
}

const Rectangle &Button::getRectangle() const noexcept { return rectangle_; }