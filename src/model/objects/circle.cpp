/**
 * @file circle.cpp
 * @author Manuel Rocca
 * @brief Source file for the Circle class
 * @date 2024
 *
 */

#include "circle.hpp"

Circle::Circle(Point &center, double &radius) : Object{center}, radius_(radius) {}

double Circle::get_radius() const noexcept { return radius_; }
