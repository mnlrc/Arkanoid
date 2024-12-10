/**
 * @file brick.cpp
 * @author Manuel Rocca
 * @brief Source file for the Brick class
 * @date 2024
 *
 */

#include "brick.hpp"

Brick::Brick(Point pt, double w, double h, bool breakable): Rectangle{pt, w, h}, breakable_(breakable) {}

Brick::~Brick() = default;

bool Brick::isBreakable() const noexcept { return breakable_; };

bool Brick::isBroken() const noexcept { return broken_; };

void Brick::setBroken() noexcept { broken_ = true; };