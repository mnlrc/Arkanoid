/**
 * @file power_up.cpp
 * @author Manuel Rocca
 * @brief Source file for the PowerUp class
 * @date 2025
 *
 */

#include "power_up.hpp"

PowerUp::PowerUp(Point center, Color inner_color, Color outer_color, Power power) : Rectangle{center, POWER_UP_WIDTH, POWER_UP_HEIGHT, inner_color, outer_color}, power_(power), is_falling_(true) {}