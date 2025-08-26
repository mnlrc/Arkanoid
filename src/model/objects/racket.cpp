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
    set_center(center_);
}

void Racket::set_center(const Point &new_point) noexcept
{
    double RACKET_LEFT = new_point.x_ - width_ / 2;
    double RACKET_RIGHT = new_point.x_ + width_ / 2;

    if (RACKET_LEFT <= 0)
    {
        double max_left = width_ / 2; // max pos of the racket on the left
        center_ = Point{max_left, center_.y_};
    }
    else if (RACKET_RIGHT >= WINDOW_WIDTH)
    {
        double max_right = WINDOW_WIDTH - (width_ / 2); // max pos of the racket on the right
        center_ = Point{max_right, center_.y_};
    }
    else
    {
        center_ = new_point;
    }
}