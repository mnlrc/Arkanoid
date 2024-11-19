/**
 * @file racket.cpp
 * @author Manuel Rocca
 * @brief Source file for the Racket class
 * @date 2024
 *
 */
#include <iostream>
#include "racket.hpp"

Racket::Racket(float x, float w) : x_(x), width_(w) {
    left_border = x_ - (width_ / 2);
    right_border = x_ + (width_ / 2);
}

float Racket::getX() const noexcept { return x_; }

float Racket::getWidth() const noexcept { return width_; }

float Racket::getLeftBorder() const noexcept { return left_border; }

float Racket::getRightBorder() const noexcept { return right_border; }

void Racket::setX(float x) noexcept { x_ = x; }

double Racket::returnAngle(int x) { return (30 + (120 * (1 - x/width_))); }

void Racket::move(float dx){
    if (IsInBounds(dx)){
        x_ += dx;
        // Reevaluate the positions of the borders
        left_border = x_ - (width_ / 2);
        right_border = x_ + (width_ / 2);
    }
}

bool Racket::IsInBounds(float dx) const {
    return !((left_border + dx) < 0 || (right_border + dx) > WINDOW_WIDTH);
}