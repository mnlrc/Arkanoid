/**
 * @file power_up.hpp
 * @author Manuel Rocca
 * @brief Header file for the PowerUp class
 * @date 2025
 *
 */

#ifndef POWER_UP_HPP
#define POWER_UP_HPP

#define POWER_UP_WIDTH WINDOW_WIDTH * 0.05
#define POWER_UP_HEIGHT WINDOW_HEIGHT * 0.05

#include "rectangle.hpp"
#include "../../global_variables.hpp"

#include <unordered_map>

enum class Power : int
{
    LASER = 0, // shoot lasers from the racket
    ENLARGE,   // enlarge the rackets width
    CATCH,     // catch ball when it hits the racket
    SLOW,      // slow the balls travel speed
    STOP,      // ball multiplier
    PLAYER,    // add life
    NONE,
};

const std::unordered_map<Power, Color> POWER_UP_COLOR = {
    {Power::LASER, Color::RED},
    {Power::ENLARGE, Color::BLUE},
    {Power::CATCH, Color::GREEN},
    {Power::SLOW, Color::ORANGE},
    {Power::STOP, Color::CYAN},
    {Power::PLAYER, Color::GREY},
    {Power::NONE, Color::NONE}};

class PowerUp : public Rectangle
{
public:
    PowerUp(Point center, Power power);

    ~PowerUp() = default;

    Power get_power() const noexcept;

    bool is_falling() const noexcept;

    bool is_active() const noexcept;

    void activate() noexcept;

private:
    Power power_;
    bool is_falling_;
    bool is_active_;
};

#endif