#include "brick.hpp"

Brick::Brick(unsigned w, unsigned h): width_(w), height_(h) {}

Brick::~Brick() = default;

unsigned Brick::getHeight() const noexcept { return height_; }

unsigned Brick::getWidth() const noexcept { return width_; }