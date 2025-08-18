/**
 * @file raquette.hpp
 * @author Manuel Rocca
 * @brief Header file for the Racket class
 * @date 2024
 *
 */

#ifndef racket_HPP
#define racket_HPP

#include "point.hpp"
#include "rectangle.hpp"
#include "global_variables.hpp"

/**
 * @class Racket
 * @brief Represents the racket used by the player
 *        to bounce back the ball.
 */

class Racket : public Rectangle
{
public:
    /**
     * @brief Default constructor of the Racket class
     */
    Racket(double &racket_width_percentage);

    // #### Destructor ####
    /**
     * @brief Destructor for the Racket class
     */
    ~Racket() = default;
    
    double get_width_percentage() const noexcept;

    double get_speed() const noexcept;

private:
    double racket_width_percentage_; // percentage of the windows width
    double speed_ = 10;
};

#endif