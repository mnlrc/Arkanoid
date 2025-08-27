/**
 * @file object.hpp
 * @author Manuel Rocca
 * @brief Header file for the Object class.
 * @date 2025
 */

#ifndef OBJECT_HPP
#define OBJECT_HPP

// #### Internal inclusions ####
#include "../../global_variables.hpp"
#include "point.hpp"

/**
 * @brief A parent class that holds common attributes
 * of many other objects. Used for code refactoring
 * using the inheritance mecanism given by C++ (and
 * many other langages)
 * 
 */
class Object
{
public:
    /**
     * @brief Construct a new Object object
     *
     */
    Object(Point &center, Color &inner_color, Color &outer_color);
    Object(Color &inner_color, Color &outer_color);
    Object(Color &color);
    Object(Point &center);
    Object() = default;

    /**
     * @brief Destroy the Object object
     * Virtual destructor because of inheritance
     * 
     */
    virtual ~Object() = default;

    /**
     * @brief Get the inner color of the object
     * 
     * @return Color 
     */
    Color get_inner_color() const noexcept;

    /**
     * @brief Get the outer color of the object
     * 
     * @return Color 
     */
    Color get_outer_color() const noexcept;

    /**
     * @brief Get the center of the object
     * 
     * @return Point 
     */
    Point get_center() const noexcept;

    /**
     * @brief Set the center of the object
     * 
     * @param new_point 
     */
    virtual void set_center(const Point &new_point) noexcept;

protected:
    Point center_;
    Color inner_color_;
    Color outer_color_;
};

#endif