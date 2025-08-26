/**
 * @file laser.cpp
 * @author Manuel Rocca
 * @brief Source file for the Laser class
 * @date 2025
 *
 */

#include "laser.hpp"

Laser::Laser(Point center) : Rectangle{center, LASER_WIDTH, LASER_HEIGHT, LASER_INNER_COLOR, LASER_OUTER_COLOR}, is_active_(false), speed_(Point{LASER_X_SPEED, LASER_Y_SPEED}), has_hit_(false) {}

void Laser::launch() noexcept { is_active_ = true; }

void Laser::has_hit() noexcept { has_hit_ = true; }

bool Laser::is_launched() const noexcept { return is_active_; }

Point Laser::get_speed() const noexcept { return speed_; }

bool Laser::was_used() const noexcept { return has_hit_; }