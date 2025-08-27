/**
 * @file raquette.hpp
 * @author Manuel Rocca
 * @brief Header file for the Racket class
 * @date 2025
 *
 */

#ifndef racket_HPP
#define racket_HPP

#include "point.hpp"
#include "rectangle.hpp"
#include "global_variables.hpp"
#include "object.hpp"

/**
 * @class Racket
 * @brief Represents the racket used by the player
 *        to bounce back the ball.
 */

class Racket final : public Rectangle
{
public:
    /**
     * @brief Default constructor of the Racket class
     */
    Racket(Color &inner_color, Color &outer_color, double &racket_width_percentage);

    double get_width_percentage() const noexcept;

    double get_speed() const noexcept;

    void enlarge(const double factor) noexcept;

    void reset_width() noexcept;

    void set_center(const Point &new_point) noexcept override;

private:
    double racket_width_percentage_; // percentage of the windows width
    double default_width_percentage_;
    double speed_ = 10;
};

#endif