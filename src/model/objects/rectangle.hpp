/**
 * @file rectangle.hpp
 * @author Manuel Rocca
 * @brief Header file for the Rectangle class
 * @date 2025
 *
 */

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "point.hpp"
#include "object.hpp"
#include "../../global_variables.hpp"

class Rectangle : public Object
{
public:
    // ##### Constructors #####
    Rectangle(Color inner_color, Color outer_color);

    Rectangle(Point center, double width, double height, Color inner_color, Color outer_color);

    Rectangle() = default;
    // ##### Destructor #####
    ~Rectangle() = default;

    // #### Getters #####

    /**
     * @brief Get the width of the racket
     * @return The witdh of the racket
     */
    double get_width() const noexcept;

    /**
     * @brief Get the height of the racket
     * @return The height of the racket
     */
    double get_height() const noexcept;

    double get_left() const noexcept;

    double get_right() const noexcept;

    double get_top() const noexcept;

    double get_bottom() const noexcept;

    void set_width(double &new_width) noexcept;

    void set_height(double &new_height) noexcept;

protected:
    double width_;
    double height_;
};

#endif