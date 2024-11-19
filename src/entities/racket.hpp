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

#define RACKET_HEIGHT 15 // height of the racket on the window
#define DEFAULT_RACKET_WIDTH 100
#define LIMIT_HEIGHT 565 // 565 is an arbitrary number chosen so that the racket isn't to close to the border of the Window
#define WINDOW_WIDTH 500

/**
 * @class Racket
 * @brief Represents the racket used by the player
 *        to bounce back the ball.
 */

class Racket {
    
    private:
        Point center_; // Coordinates of the middle of the racket
        float width_; // width of the racket
    
    public:
        // ### Constructors ###
        /**
         * @brief Constructor for the Racket class
         * @param x Initial x coordinate of the racket
         */
        Racket(Point pt);

        // #### Getters ####

        /**
         * @brief Get the x coordinate of the racket
         * @return The x coordinate of the racket
         */
        Point getCenter() const noexcept;

        /**
         * @brief Get the width of the racket
         * @return The witdh of the racket
         */
        float getWidth() const noexcept;

        // #### Setters ####

        /**
         * @brief Set the x coordinate of the racket
         * @param x The new x coordinate of the racket
         */
        void setCenter(Point pt) noexcept;

        // ### Methods ###


        /**
         * @brief Returns the angle of the ball when a collision occurs
         * @param x Position of the ball compared to the start of the racket
         */
        double returnAngle(int x);

        /**
         * @brief Changes the x coordinate of the racket
         * @param dx Position shift, can be negative
         */
        void move(float dx);

        /**
         * @brief Checks if the racket is still in bounds of the screen
         * @param dx Position shift, can be negative
         * @return True if in bounds False else
         */
        bool IsInBounds(float dx) const;

};

#endif