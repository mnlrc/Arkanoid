/**
 * @file ball.cpp
 * @author Manuel Rocca
 * @brief Source file for the Ball class
 * @date 2024
 *
 */

#include "ball.hpp"

Ball::Ball(Point &center, double &radius, Point &speed) : Circle{center, radius}, speed_(speed), is_moving_(DEFAULT_BALL_STATE), default_ball_speed_(speed) {}

Ball::Ball(Point center, double radius, bool state) : Circle{center, radius}, speed_{DEFAULT_BALL_SPEED, DEFAULT_BALL_SPEED}, is_moving_(state), default_ball_speed_{DEFAULT_BALL_SPEED, DEFAULT_BALL_SPEED} {}

Ball::Ball(Point center, double radius, Point speed, bool state) : Circle{center, radius}, speed_(speed), is_moving_(state), default_ball_speed_(speed) {}

Point Ball::get_speed() const noexcept { return speed_; }

bool Ball::get_state() const noexcept { return is_moving_; };

void Ball::reset_speed() noexcept { speed_ = default_ball_speed_; }

void Ball::set_speed(const Point &new_speed) noexcept { speed_ = new_speed; };

void Ball::change_state() noexcept { is_moving_ = !is_moving_; };

void Ball::slow() noexcept
{
    Point new_speed = get_speed();
    new_speed.x_ = new_speed.x_ * SLOW_PERCENTAGE;
    new_speed.y_ = new_speed.y_ * SLOW_PERCENTAGE;
    set_speed(new_speed);
}