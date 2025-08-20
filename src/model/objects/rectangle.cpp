/**
 * @file rectangle.cpp
 * @author Manuel Rocca
 * @brief Source file for the Rectangle class
 * @date 2024
 *
 */

#include "rectangle.hpp"

Rectangle::Rectangle(Color inner_color, Color outer_color) : Object{inner_color, outer_color} {}

Rectangle::Rectangle(Point &center, double &width, double &height, Color &inner_color, Color &outer_color)
    : Object{center, inner_color, outer_color}, width_{width}, height_{height} {}

double Rectangle::get_width() const noexcept { return width_; }

double Rectangle::get_height() const noexcept { return height_; }

void Rectangle::set_width(double &new_width) noexcept { width_ = new_width; }

void Rectangle::set_height(double &new_height) noexcept { height_ = new_height; }
