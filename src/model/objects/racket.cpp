/**
 * @file racket.cpp
 * @author Manuel Rocca
 * @brief Source file for the Racket class
 * @date 2024
 *
 */

#include "racket.hpp"

Racket::Racket(Color &inner_color, Color &outer_color, double &racket_width_percentage) : Rectangle{inner_color, outer_color}, racket_width_percentage_(racket_width_percentage), default_width_percentage_(racket_width_percentage) {}

double Racket::get_width_percentage() const noexcept { return racket_width_percentage_; }

double Racket::get_speed() const noexcept { return speed_; }

void Racket::enlarge(const double factor) noexcept
{
    double new_width = get_width() * factor;
    set_width(new_width);
}

void Racket::reset_width() noexcept
{
    double default_width = WINDOW_WIDTH * default_width_percentage_;
    set_width(default_width);
}