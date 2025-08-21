/**
 * @file score.cpp
 * @author Manuel Rocca
 * @brief Source file for the Score class
 * @date 2024
 *
 */

#include "score.hpp"

Score::Score() : rectangle_{Point{WINDOW_WIDTH / 2, WINDOW_HEIGHT * 0.8}, 0, 0, Color::BLACK, Color::BLACK}, score_(STARTING_SCORE) {}

unsigned Score::get_score() const noexcept { return score_; };

void Score::set_score(unsigned new_score) noexcept { score_ = new_score; };

void Score::add_score(unsigned points) noexcept { score_ += points; };

Point Score::get_center() const noexcept { return rectangle_.get_center(); };