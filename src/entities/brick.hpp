/**
 * @file brick.hpp
 * @author Manuel Rocca
 * @brief Header file for the Brick class
 * @date 2024
 *
 */

#ifndef BRICK_HPP
#define BRICK_HPP

#include "point.hpp"
#include "rectangle.hpp"

#define BRICK_WIDTH 35
#define BRICK_HEIGHT 20
#define DEFAULT_BREAKABLE_STATE true

class Brick: public Rectangle{

    // Possibilité de réutilisation :

    // Vous pouvez décider de "réparer" une brique plus tard en réinitialisant son état (isDestroyed = false), par exemple pour un power-up.
    
    private:
        const bool breakable_; // for later phases 
        bool broken_ = false;
    
    public:
        // #### Constructors ####
        /**
         * @brief Constructor of the Brick class
         * @param pt Coordinates of the brick
         * @param w Width of the brick
         * @param h Height of the brick
         * @param breakabale Breakability of the brick
         */
        Brick(Point pt, double w, double h, bool breakable);

        // Brick &operator=(const Brick &) = default;
        // Brick &operator=(Brick &&)      = default;

        // #### Destructor ####
        ~Brick();

        // #### Getters ####
        bool isBreakable() const noexcept;
        bool isBroken() const noexcept;
        
        // #### Setters ####
        void setBroken() noexcept;
};

#endif