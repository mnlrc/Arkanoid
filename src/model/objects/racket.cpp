/**
 * @file racket.cpp
 * @author Manuel Rocca
 * @brief Source file for the Racket class
 * @date 2024
 *
 */

#include "racket.hpp"

Racket::Racket(double &racket_width_percentage) : racket_width_percentage_(racket_width_percentage) {}

// Racket::Racket() : Rectangle{Point{WINDOW_WIDTH / 2, WINDOW_HEIGHT - 20}, WINDOW_WIDTH / 6, WINDOW_HEIGHT / 50}, speed_(DEFAULT_RACKET_SPEED) {}

double Racket::get_width_percentage() const noexcept { return racket_width_percentage_; }