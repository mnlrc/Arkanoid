/**
 * @file power_up.hpp
 * @author Manuel Rocca
 * @brief Header file for the PowerUp class
 * @date 2025
 *
 */

#ifndef POWER_UP_HPP
#define POWER_UP_HPP

// #### Internal inclusions ####
#include "rectangle.hpp"
#include "../../log/logger.hpp"
#include "../../global_variables.hpp"

// #### C++ inclusions ####
#include <unordered_map>
#include <chrono>

using namespace std::chrono;

constexpr double POWER_UP_WIDTH = WINDOW_WIDTH * 0.03;
constexpr double POWER_UP_HEIGHT = WINDOW_HEIGHT * 0.03;
constexpr int FALLING_SPEED = 3;

const double RACKET_ENLARGE_PERCENTAGE = 2.0;

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

const std::unordered_map<Power, int64_t> POWER_UP_DURATION = {
    {Power::LASER, 10.0},
    {Power::CATCH, 15.0},
    {Power::SLOW, 5.0}};

class PowerUp final : public Rectangle
{
public:
    /**
     * @brief Construct a new Power Up object
     *
     */
    PowerUp(Point center, Power power);
    PowerUp();

    /**
     * @brief Get the power held within the power up
     *
     * @return Power
     */
    Power get_power() const noexcept;

    /**
     * 
     * @return true if the power up is in a falling state 
     * @return false otherwise
     */
    bool is_falling() const noexcept;

    /**
     * 
     * @return true if the power up is active
     * @return false otherwise
     */
    bool is_active() const noexcept;

    /**
     * @brief Sets the power up as active, stops
     * its fall and starts its time active
     * 
     */
    void activate() noexcept;

    /**
     * @brief Returns a value between 0 and 1 reprensenting
     * the time left of the power up's active time
     * 
     * @return double 
     */
    double progress() noexcept;

    /**
     * @brief Stop the fall of the power up
     * 
     */
    void stop_fall() noexcept;

private:
    Power power_;
    bool is_falling_;
    bool is_active_;
    steady_clock::time_point time_active_; // to mesure its active time, all power ups don't have a time limit
};

#endif