/**
 * @file racket.cpp
 * @author Manuel Rocca
 * @brief Source file for the Racket class
 * @date 2024
 *
 */
#include <iostream>
#include "racket.hpp"

Racket::Racket(Point pt, float w, float h): center_(pt), width_(w), height_(h), speed_(DEFAULT_RACKET_SPEED) {}

Racket::~Racket() = default;

Point Racket::getCenter() const noexcept { return center_; }

float Racket::getWidth() const noexcept { return width_; }

float Racket::getHeight() const noexcept { return height_; }

unsigned Racket::getSpeed() const noexcept { return speed_; };

void Racket::setCenter(float dx) noexcept { center_.x_ = dx; }

double Racket::returnAngle(int x) { return (30 + (120 * (1 - x/width_))); }

// void Racket::move(float dx){
//     if (IsInBounds(dx)){
//         x_ += dx;
//         // Reevaluate the positions of the borders
//         left_border = x_ - (width_ / 2);
//         right_border = x_ + (width_ / 2);
//     }
// }

// bool Racket::IsInBounds(float dx) const {
//     return !((left_border + dx) < 0 || (right_border + dx) > WINDOW_WIDTH);
// }