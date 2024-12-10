#include "entities.hpp"


Racket Entities::getRacket() const noexcept { return racket_; };

std::vector<Ball> Entities::getBalls() const noexcept { return balls_; };

std::vector<std::vector<Brick>> Entities::getBricks() const noexcept { return bricks_; };

Score Entities::getScore() const noexcept { return score_; };