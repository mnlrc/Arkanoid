/**
 * @file power_up.hpp
 * @author Manuel Rocca
 * @brief Header file for the PowerUp class
 * @date 2025
 *
 */

#ifndef POWER_UP_HPP
#define POWER_UP_HPP

#include "rectangle.hpp"
#include "../../log/logger.hpp"
#include "../../global_variables.hpp"

#include <unordered_map>
#include <chrono>

constexpr double POWER_UP_WIDTH = WINDOW_WIDTH * 0.03;
constexpr double POWER_UP_HEIGHT = WINDOW_HEIGHT * 0.03;
constexpr int FALLING_SPEED = 3;

using namespace std::chrono;

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

const double RACKET_ENLARGE_PERCENTAGE = 2.0;

const std::unordered_map<Power, Color> POWER_UP_COLOR = {
    {Power::LASER, Color::RED},
    {Power::ENLARGE, Color::BLUE},
    {Power::CATCH, Color::GREEN},
    {Power::SLOW, Color::ORANGE},
    {Power::STOP, Color::CYAN},
    {Power::PLAYER, Color::GREY},
    {Power::NONE, Color::NONE}};

const std::unordered_map<Power, int64_t> POWER_UP_DURATION = {
    {Power::LASER, 10.0},
    {Power::CATCH, 15.0},
    {Power::SLOW, 5.0}};

class PowerUp final : public Rectangle
{
public:
    PowerUp(Point center, Power power);

    PowerUp();

    ~PowerUp() = default;

    Power get_power() const noexcept;

    bool is_falling() const noexcept;

    bool is_active() const noexcept;

    void activate() noexcept;

    double progress() noexcept;

    void stop_fall() noexcept;

private:
    Power power_;
    bool is_falling_;
    bool is_active_;
    steady_clock::time_point time_active_;
};

#endif