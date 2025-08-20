/**
 * @file ball.cpp
 * @author Manuel Rocca
 * @brief Source file for the Ball class
 * @date 2024
 *
 */

#include "ball.hpp"

Ball::Ball(Point &center, double &radius, Point &speed) : Circle{center, radius}, speed_(speed), is_moving_(DEFAULT_BALL_STATE) {}

Point Ball::get_speed() const noexcept { return speed_; }

bool Ball::get_state() const noexcept { return is_moving_; };

void Ball::set_speed(const Point &new_speed) noexcept { speed_ = new_speed; };

void Ball::change_state() noexcept { is_moving_ = !is_moving_; };
