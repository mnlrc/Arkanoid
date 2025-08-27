/**
 * @file rectangle.hpp
 * @author Manuel Rocca
 * @brief Header file for the Rectangle class
 * @date 2025
 *
 */

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

// #### Internal inclusions ####
#include "point.hpp"
#include "object.hpp"
#include "../../global_variables.hpp"

class Rectangle : public Object
{
public:
    /**
     * @brief Construct a new Rectangle object
     *
     */
    Rectangle(Color inner_color, Color outer_color);
    Rectangle(Point center, double width, double height, Color inner_color, Color outer_color);
    Rectangle() = default;

    /**
     * @brief Get the width of the rectangle
     * @return The witdh of the rectangle
     */
    double get_width() const noexcept;

    /**
     * @brief Get the height of the rectangle
     * @return The height of the rectangle
     */
    double get_height() const noexcept;

    /**
     * @brief Get the left extremity of the rectangle
     *
     * @return double
     */
    double get_left() const noexcept;

    /**
     * @brief Get the right extremity of the rectangle
     *
     * @return double
     */
    double get_right() const noexcept;

    /**
     * @brief Get the top extremity of the rectangle
     *
     * @return double
     */
    double get_top() const noexcept;

    /**
     * @brief Get the bottom extremity of the rectangle
     *
     * @return double
     */
    double get_bottom() const noexcept;

    /**
     * @brief Set the width of the rectangle
     * 
     * @param new_width 
     */
    void set_width(double &new_width) noexcept;

    /**
     * @brief Set the height of the rectangle
     * 
     * @param new_height 
     */
    void set_height(double &new_height) noexcept;

protected:
    double width_;
    double height_;
};

#endif