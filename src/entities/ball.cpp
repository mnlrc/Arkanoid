#include "ball.hpp"

Ball::Ball(Point c, float r): center_(c), radius_(r) {}

Ball::~Ball() = default;

Point Ball::getCenter() const noexcept { return center_; }

float Ball::getRadius() const noexcept { return radius_; }

void Ball::setCenter(const Point pt) noexcept { center_ = pt; }

