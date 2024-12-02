/**
 * @file brick.cpp
 * @author Manuel Rocca
 * @brief Source file for the Brick class
 * @date 2024
 *
 */

#include "brick.hpp"

Brick::Brick(float w, float h, Point pt): width_(w), height_(h), center_(pt) {}

Brick::~Brick() = default;

float Brick::getHeight() const noexcept { return height_; }

float Brick::getWidth() const noexcept { return width_; }

Point Brick::getCenter() const noexcept { return center_; }