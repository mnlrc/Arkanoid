/**
 * @file score.cpp
 * @author Manuel Rocca
 * @brief Source file for the Score class
 * @date 2025
 *
 */

#include "score.hpp"

Score::Score() : Rectangle{Point{WINDOW_WIDTH * SCORE_WIDTH_PERCENTAGE, WINDOW_HEIGHT * SCORE_HEIGHT_PERCENTAGE}, 0, 0, Color::BLACK, Color::BLACK}, score_(STARTING_SCORE) {}

unsigned Score::get_score() const noexcept { return score_; };

void Score::add_score(unsigned points) noexcept { score_ += points; };

void Score::set_score(unsigned new_score) noexcept { score_ = new_score; };
