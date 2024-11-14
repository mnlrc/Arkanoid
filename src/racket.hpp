/**
 * @file raqutte.hpp
 * @author Manuel Rocca
 * @brief Header file for the Racket class
 * @date 2024
 *
 */

#ifndef racket_HPP
#define racket_HPP

/**
 * @class Racket
 * @brief Represents the racket used by the player
 *        to bounce back the ball.
 */

class Racket {
    
    private:
        int x_; // x coordinate of the racket
        unsigned width_; // width of the racket
    
    public:
        // ### Constructors ###
        /**
         * @brief Constructor for the Racket class
         *
         * @param x Initial x coordinate of the racket
         */
        Racket(int x);

        // #### Getters ####

        /**
         * @brief Get the x coordinate of the racket
         * @return The x coordinate of the racket
         */
        int getX() const noexcept;

        /**
         * @brief Get the width of the racket
         * @return The witdh of the racket
         */
        unsigned getWidth() const noexcept;

        // #### Setters ####

        /**
         * @brief Set the x coordinate of the racket
         * @param x The new x coordinate of the racket
         */
        void setX(int x) noexcept;

        // ### Methods ###

        double returnAngle(int x);
};

#endif