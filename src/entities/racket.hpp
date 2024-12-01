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

#define DEFAULT_RACKET_SPEED 150

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
        unsigned speed_; // speed of the racket

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
        unsigned getSpeed() const noexcept;


        // #### Setters ####
        /**
         * @brief Set the x coordinate of the racket
         * @param x The new x coordinate of the racket
         */
        void setCenter(float dx) noexcept;


        // #### Methods ####
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