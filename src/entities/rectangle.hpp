/**
 * @file rectangle.hpp
 * @author Manuel Rocca
 * @brief Header file for the Rectangle class
 * @date 2024
 *
 */

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "point.hpp"

class Rectangle {

    protected:
        Point center_;
        double width_;
        double height_;

    public:
        // ##### Constructor #####
        Rectangle(Point pt, double w, double h);

        // ##### Destructor #####
        ~Rectangle();
        
        // #### Getters #####
        /**
         * @brief Get the x coordinate of the racket
         * @return The x coordinate of the racket
         */
        Point getCenter() const noexcept;

        /**
         * @brief Get the width of the racket
         * @return The witdh of the racket
         */
        double getWidth() const noexcept;

        /**
         * @brief Get the height of the racket
         * @return The height of the racket
         */
        double getHeight() const noexcept;
};

#endif