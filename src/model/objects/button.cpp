/**
 * @file button.cpp
 * @author Manuel Rocca
 * @brief Source file for the Button class
 * @date 2025
 *
 */

#include "button.hpp"

Button::Button(const std::vector<Text> &texts, Point center, double width, double height, Color inner_color, Color outer_color)
    : texts_(texts), idx_(0), rectangle_(Rectangle{center, width, height, inner_color, outer_color}) {}

const Text &Button::get_selected_text() const noexcept { return texts_[idx_]; }

void Button::next_text()
{
    if (texts_.size() > 1)
        idx_ = (idx_ + 1) % texts_.size();
}

void Button::previous_text()
{
    if (texts_.size() > 1)
        idx_ = (idx_ + texts_.size() - 1) % texts_.size();
}

void Button::set_selected_text(size_t idx)
{
    if (idx < texts_.size())
    {
        idx_ = idx;
    }
    else
    {
        Logger::log("[ERROR] Index out of bounds for Button texts");
    }
}

const Rectangle &Button::get_rectangle() const noexcept { return rectangle_; }