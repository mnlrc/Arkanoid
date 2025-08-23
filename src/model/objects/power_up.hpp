/**
 * @file power_up.hpp
 * @author Manuel Rocca
 * @brief Header file for the PowerUp class
 * @date 2025
 *
 */

#ifndef POWER_UP_HPP
#define POWER_UP_HPP

#define POWER_UP_WIDTH WINDOW_WIDTH * 0.1
#define POWER_UP_HEIGHT WINDOW_HEIGHT * 0.1

#include "rectangle.hpp"

class PowerUp : public Rectangle
{
public:
    PowerUp(Point center, Color inner_color, Color outer_color, Power power);

    ~PowerUp() = default;

private:
    Power power_;
    bool is_falling_;
};

#endif