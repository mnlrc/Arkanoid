#include "ball.hpp"

Ball::Ball(Point c, float r, unsigned sX, unsigned sY): center_(c), radius_(r), speedX_(sX), speedY_(sY), isMoving(DEFAULT_BALL_STATE) {}

Ball::~Ball() = default;

Point Ball::getCenter() const noexcept { return center_; }

float Ball::getRadius() const noexcept { return radius_; }

float Ball::getSpeedX() const noexcept { return speedX_; }

float Ball::getSpeedY() const noexcept { return speedY_; }

bool Ball::getState() const noexcept { return isMoving; };

void Ball::setCenter(const Point pt) noexcept { center_ = pt; }

void Ball::setSpeedX(const float sX) noexcept { speedX_ = sX; };

void Ball::setSpeedY(const float sY) noexcept { speedY_ = sY; };

void Ball::changeState() noexcept { isMoving = !isMoving; };
