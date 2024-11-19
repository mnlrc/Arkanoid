/**
 * @file racket.cpp
 * @author Manuel Rocca
 * @brief Source file for the Racket class
 * @date 2024
 *
 */
#include <iostream>
#include "racket.hpp"

Racket::Racket(Point pt) : center_(pt), width_(DEFAULT_RACKET_WIDTH) {}

Point Racket::getCenter() const noexcept { return center_; }

float Racket::getWidth() const noexcept { return width_; }

void Racket::setCenter(Point pt) noexcept { center_ = pt; }

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