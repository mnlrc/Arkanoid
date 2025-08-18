/**
 * @file racket.cpp
 * @author Manuel Rocca
 * @brief Source file for the Racket class
 * @date 2024
 *
 */

#include "racket.hpp"

Racket::Racket(double &racket_width_percentage) : racket_width_percentage_(racket_width_percentage) {}

double Racket::get_width_percentage() const noexcept { return racket_width_percentage_; }

double Racket::get_speed() const noexcept { return speed_; }