/**
 * @file score.cpp
 * @author Manuel Rocca
 * @brief Source file for the Score class
 * @date 2024
 *
 */

#include "score.hpp"

Score::Score() {
    pos_ = {0, 0};
    score_ = 0;
}

unsigned Score::getScore() const noexcept{ return score_; };

void Score::setScore(unsigned sc) noexcept { score_ = sc; };

void Score::incScore() { score_ += 100; };
