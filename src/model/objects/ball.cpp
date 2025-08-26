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

void Ball::reset_speed() noexcept
{
    speed_.x_ = std::copysign(std::abs(default_ball_speed_.x_), speed_.x_);
    speed_.y_ = std::copysign(std::abs(default_ball_speed_.y_), speed_.y_);
}

void Ball::set_speed(const Point &new_speed) noexcept { speed_ = new_speed; };

void Ball::change_state() noexcept { is_moving_ = !is_moving_; };

void Ball::apply_slow() noexcept
{
    current_slow_factor_ *= SLOW_FACTOR;

    speed_.x_ = std::copysign(std::abs(default_ball_speed_.x_) * current_slow_factor_, speed_.x_);
    speed_.y_ = std::copysign(std::abs(default_ball_speed_.y_) * current_slow_factor_, speed_.y_);
}

void Ball::update_speed_progress(double progress) noexcept
{
    // using linear interpolation
    double factor = current_slow_factor_ + (1.0 - current_slow_factor_) * progress;
    speed_.x_ = std::copysign(std::abs(default_ball_speed_.x_) * factor, speed_.x_);
    speed_.y_ = std::copysign(std::abs(default_ball_speed_.y_) * factor, speed_.y_);
}