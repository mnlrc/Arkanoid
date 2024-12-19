/**
 * @file score.hpp
 * @author Manuel Rocca
 * @brief Header file for the Score class
 * @date 2024
 *
 */

#ifndef SCORE_HPP
#define SCORE_HPP

#include "point.hpp"
#include "global_variables.hpp"


class Score {
    private:
        unsigned score_;
        Point pos_;
    public:
        Score();
        unsigned getScore() const noexcept;
        void setScore(unsigned sc) noexcept;
        void incScore();

};


#endif