/**
 * @file score.hpp
 * @author Manuel Rocca
 * @brief Header file for the Score class
 * @date 2025
 *
 */

#ifndef SCORE_HPP
#define SCORE_HPP

// #### Internal inclusions ####
#include "global_variables.hpp"
#include "rectangle.hpp"

constexpr unsigned STARTING_SCORE = 0;
constexpr double SCORE_HEIGHT_PERCENTAGE = 0.8;
constexpr double SCORE_WIDTH_PERCENTAGE = 0.5;

/**
 * @brief Class that holds the score value as well as
 * a rectangle that helps the view draw the score
 *
 */
class Score final: public Rectangle
{
public:
    /**
     * @brief Construct a new Score object
     *
     */
    Score();

    /**
     * @brief Get the score 
     * 
     * @return unsigned 
     */
    unsigned get_score() const noexcept;

    /**
     * @brief Add points to the current score
     * 
     * @param points 
     */
    void add_score(unsigned points) noexcept;

    /**
     * @brief Set the score to a new value
     * 
     * @param new_score 
     */
    void set_score(unsigned new_score) noexcept;

private:
    unsigned score_;
};

#endif