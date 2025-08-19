/**
 * @file object.cpp
 * @author Manuel Rocca
 * @brief Source file for the Object class.
 * @date 2025
 */

#include "object.hpp"

Object::Object(Color inner_color, Color outer_color) : inner_color_{inner_color}, outer_color_{outer_color} {}

Object::Object(Color color) : inner_color_{color}, outer_color_{Color::BLACK} {}

Color Object::get_inner_color() const noexcept { return inner_color_; }

Color Object::get_outer_color() const noexcept { return outer_color_; }