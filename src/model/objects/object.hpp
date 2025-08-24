/**
 * @file object.hpp
 * @author Manuel Rocca
 * @brief Header file for the Object class.
 * @date 2025
 */

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "../../global_variables.hpp"
#include "point.hpp"

class Object
{
public:
    Object(Point &center, Color &inner_color, Color &outer_color);

    Object(Color &inner_color, Color &outer_color);

    Object(Color &color);

    Object(Point &center);

    Object() = default;

    ~Object() = default;

    Color get_inner_color() const noexcept;
    Color get_outer_color() const noexcept;

    Point get_center() const noexcept;

    void set_center(const Point &new_point) noexcept;

protected:
    Point center_;
    Color inner_color_;
    Color outer_color_;
};

#endif