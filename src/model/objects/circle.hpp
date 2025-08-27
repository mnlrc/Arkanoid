/**
 * @file circle.hpp
 * @author Manuel Rocca
 * @brief Header file for the Circle class
 * @date 2025
 *
 */

#ifndef CIRCLE_HPP
#define CIRCLE_HPP

// #### Internal inclusions ####
#include "point.hpp"
#include "object.hpp"

class Circle : public Object
{
public:
    /**
     * @brief Construct a new Circle object
     *
     */
    Circle(Point &center, double &radius);
    Circle(Point center, double radius, Color inner_color, Color outer_color);

    /**
     * @brief Get the radius of the circle
     * 
     * @return double 
     */
    double get_radius() const noexcept;

protected:
    double radius_;
};

#endif