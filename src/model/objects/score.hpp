/**
 * @file score.hpp
 * @author Manuel Rocca
 * @brief Header file for the Score class
 * @date 2024
 *
 */

#ifndef SCORE_HPP
#define SCORE_HPP

#define STARTING_SCORE 0

#include "global_variables.hpp"
#include "rectangle.hpp"

class Score
{
public:
    Score();

    unsigned get_score() const noexcept;

    void set_score(unsigned new_score) noexcept;

    void add_score(unsigned points) noexcept;

    Point get_center() const noexcept;

private:
    Rectangle rectangle_;
    unsigned score_;
};

#endif