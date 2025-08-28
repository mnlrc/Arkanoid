/**
 * @file raquette.hpp
 * @author Manuel Rocca
 * @brief Header file for the Racket class
 * @date 2025
 *
 */

#ifndef racket_HPP
#define racket_HPP

// #### Internal inclusions ####
#include "point.hpp"
#include "rectangle.hpp"
#include "global_variables.hpp"
#include "object.hpp"

constexpr double RACKET_HEIGHT = WINDOW_HEIGHT / 25;
constexpr double RACKET_VERTICAL_POS = 0.955; // the percentage of the position on the window
constexpr double DEFAULT_RACKET_WIDTH_PERCENTAGE = 0.25;
constexpr double DEFAULT_RACKET_SPEED = 10;
constexpr Color DEFAULT_INNER_COLOR = Color::WHITE;
constexpr Color DEFAULT_OUTER_COLOR = Color::BLACK;

/**
 * @class Racket
 * @brief Represents the racket used by the player
 *        to bounce back the ball
 */
class Racket final : public Rectangle
{
public:
    /**
     * @brief Construct a new Racket object
     *
     * @param inner_color
     * @param outer_color
     * @param racket_width_percentage relative to the window's width
     */
    Racket(Color &inner_color, Color &outer_color, double &racket_width_percentage);

    /**
     * @brief Get the width percentage of the racket
     *
     * @return double
     */
    double get_width_percentage() const noexcept;

    /**
     * @brief Get the speed of the racket
     *
     * @return double
     */
    double get_speed() const noexcept;

    /**
     * @brief Enlarge the racket based on the given factor
     * 
     * @param factor 
     */
    void enlarge(const double factor) noexcept;

    /**
     * @brief Reset the racket's width
     * 
     */
    void reset_width() noexcept;

    /**
     * @brief Overriden set_center function to replace the racket within
     * the bounds of the screen if it goes out of it
     * 
     * @param new_point 
     */
    void set_center(const Point &new_point) noexcept override;

private:
    double racket_width_percentage_; // percentage of the windows width
    double default_width_percentage_;
    double speed_ = DEFAULT_RACKET_SPEED;
};

#endif