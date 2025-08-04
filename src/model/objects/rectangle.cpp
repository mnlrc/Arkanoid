/**
 * @file rectangle.cpp
 * @author Manuel Rocca
 * @brief Source file for the Rectangle class
 * @date 2024
 *
 */

#include "rectangle.hpp"

Rectangle::Rectangle(Point pt, double w, double h) : center_(pt), width_(w), height_(h) {}

Rectangle::~Rectangle() = default;

Point Rectangle::getCenter() const noexcept { return center_; }

double Rectangle::getWidth() const noexcept { return width_; }

double Rectangle::getHeight() const noexcept { return height_; }
