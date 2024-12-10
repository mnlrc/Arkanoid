/**
 * @file ball.cpp
 * @author Manuel Rocca
 * @brief Source file for the Ball class
 * @date 2024
 *
 */

#include "ball.hpp"

Ball::Ball(Point c, double r, Point s): center_(c), radius_(r), speed_(s), isMoving(DEFAULT_BALL_STATE) {}

Ball::~Ball() = default;

Point Ball::getCenter() const noexcept { return center_; }

double Ball::getRadius() const noexcept { return radius_; }

Point Ball::getSpeed() const noexcept { return speed_; }

bool Ball::getState() const noexcept { return isMoving; };

void Ball::setCenter(const Point pt) noexcept { center_ = pt; }

void Ball::setSpeed(const Point s) noexcept { speed_ = s; };

void Ball::changeState() noexcept { isMoving = !isMoving; };
