/**
 * @file rectangle.cpp
 * @author Manuel Rocca
 * @brief Source file for the Rectangle class
 * @date 2024
 *
 */

#include "rectangle.hpp"

Rectangle::Rectangle(Point pt, double w, double h) : center_(pt), width_(w), height_(h) {}

Point Rectangle::getCenter() const noexcept { return center_; }

double Rectangle::getWidth() const noexcept { return width_; }

double Rectangle::getHeight() const noexcept { return height_; }

void Rectangle::set_center(Point &new_center) noexcept { center_ = new_center; }

void Rectangle::set_width(double &new_width) noexcept { width_ = new_width; }

void Rectangle::set_height(double &new_height) noexcept { height_ = new_height; }
