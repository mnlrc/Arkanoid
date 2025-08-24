/**
 * @file laser.hpp
 * @author Manuel Rocca
 * @brief Header file for the Laser class
 * @date 2025
 *
 */

#ifndef LASER_HPP
#define LASER_HPP

#include "rectangle.hpp"
#include "../../global_variables.hpp"

const Color LASER_INNER_COLOR = Color::RED;
const Color LASER_OUTER_COLOR = Color::BLACK;
const double LASER_Y_SPEED = WINDOW_HEIGHT * 0.05;
const double LASER_X_SPEED = 0;

class Laser : public Rectangle
{
public:
    Laser(Point center, double width, double height);

    ~Laser() = default;

private:
    bool is_active_;
    Point speed_;
};

#endif