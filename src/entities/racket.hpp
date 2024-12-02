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

#define DEFAULT_RACKET_SPEED 10

/**
 * @class Racket
 * @brief Represents the racket used by the player
 *        to bounce back the ball.
 */

class Racket {
    
    private:
        Point center_; // Coordinates of the middle of the racket
        float width_; // width of the racket
        const float height_; // height of the racket
        float speed_; // speed of the racket

    public:
        // #### Constructor ####
        /**
         * @brief Constructor for the Racket class
         * @param x Initial x coordinate of the racket
         */
        Racket(Point pt, float w, float h);


        // #### Destructor ####
        /**
         * @brief Destructor for the Racket class
         */
        ~Racket();


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

        /**
         * @brief Get the height of the racket
         * @return The height of the racket
         */
        float getHeight() const noexcept;

        /**
         * @brief Get the speed of the racket
         * @return The speed of the racket
         */
        float getSpeed() const noexcept;


        // #### Setters ####
        /**
         * @brief Set the x coordinate of the racket
         * @param x The new x coordinate of the racket
         */
        void setCenter(float dx) noexcept;
};

#endif