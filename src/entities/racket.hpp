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

#define DEFAULT_RACKET_SPEED 10

/**
 * @class Racket
 * @brief Represents the racket used by the player
 *        to bounce back the ball.
 */

class Racket: public Rectangle {
    
    private:
        double speed_; // speed of the racket

    public:
        // #### Constructors ####
        /**
         * @brief Constructor of the Racket class
         * @param pt Coordinates of the racket
         * @param w Width of the racket
         * @param h Height of the racket
         * @param s Speed of the racket
         */
        Racket(Point pt, double w, double h, double s);

        /**
         * @brief Default constructor of the Racket class
         */
        Racket();


        // #### Destructor ####
        /**
         * @brief Destructor for the Racket class
         */
        ~Racket();


        // #### Getters ####
        /**
         * @brief Get the speed of the racket
         * @return The speed of the racket
         */
        double getSpeed() const noexcept;


        // #### Setters ####
        /**
         * @brief Set the x coordinate of the racket
         * @param x The new x coordinate of the racket
         */
        void setCenter(double dx) noexcept;
};

#endif