/**
 * @file circle.cpp
 * @author Manuel Rocca
 * @brief Source file for the Circle class
 * @date 2025
 *
 */

#include "circle.hpp"

Circle::Circle(Point &center, double &radius) : Object{center}, radius_(radius) {}

Circle::Circle(Point center, double radius, Color inner_color, Color outer_color)
    : Object{center, inner_color, outer_color}, radius_(radius) {}

double Circle::get_radius() const noexcept { return radius_; }
