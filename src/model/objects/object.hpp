/**
 * @file object.hpp
 * @author Manuel Rocca
 * @brief Header file for the Object class.
 * @date 2025
 */

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "../../global_variables.hpp"

class Object
{
public:
    Object(Color inner_color, Color outer_color);
    Object(Color color);
    ~Object() = default;

    Color get_inner_color() const noexcept;
    Color get_outer_color() const noexcept;

protected:
    Color inner_color_;
    Color outer_color_;
};

#endif