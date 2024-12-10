/**
 * @file brick.cpp
 * @author Manuel Rocca
 * @brief Source file for the Brick class
 * @date 2024
 *
 */

#include "brick.hpp"

Brick::Brick(Point pt, double w, double h, bool breakable): Rectangle{pt, w, h}, isBreakable(breakable) {}

Brick::~Brick() = default;
