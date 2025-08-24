/**
 * @file laser.cpp
 * @author Manuel Rocca
 * @brief Source file for the Laser class
 * @date 2025
 *
 */

#include "laser.hpp"

Laser::Laser(Point center, double width, double height) : Rectangle{center, width, height, LASER_INNER_COLOR, LASER_OUTER_COLOR}, is_active_(false), speed_(Point{LASER_X_SPEED, LASER_Y_SPEED}) {}