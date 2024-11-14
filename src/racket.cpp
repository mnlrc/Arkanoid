/**
 * @file racket.cpp
 * @author Manuel Rocca
 * @brief Source file for the Racket class
 * @date 2024
 *
 */

#include "racket.hpp"

Racket::Racket(int x) : x_(x) {}

int Racket::getX() const noexcept { return x_; }

unsigned Racket::getWidth() const noexcept { return width_; }

void Racket::setX(int x) noexcept { x_ = x; }

double Racket::returnAngle(int x) { return (30 + (120 * (1 - x/width_))); }