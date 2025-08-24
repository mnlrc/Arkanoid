/**
 * @file power_up.cpp
 * @author Manuel Rocca
 * @brief Source file for the PowerUp class
 * @date 2025
 *
 */

#include "power_up.hpp"

PowerUp::PowerUp(Point center, Power power) : Rectangle{center, POWER_UP_HEIGHT, POWER_UP_WIDTH, POWER_UP_COLOR.at(power), Color::BLACK}, power_(power), is_falling_(true), is_active_(false) {}

PowerUp::PowerUp() : Rectangle{}, power_(Power::NONE), is_falling_(false), is_active_(false) {}

Power PowerUp::get_power() const noexcept { return power_; }

bool PowerUp::is_falling() const noexcept { return is_falling_; }

bool PowerUp::is_active() const noexcept { return is_active_; }

void PowerUp::activate() noexcept
{
    is_active_ = true;
    stop_fall();
    time_active_ = clock();
}

bool PowerUp::time_up() noexcept
{
    clock_t duration = clock() - time_active_;
    double elapsed = duration / CLOCKS_PER_SEC;

    try
    {
        double time_limit = POWER_UP_DURATION.at(power_);
        if (elapsed >= time_limit)
        {
            return true;
        }
    }
    catch (const std::exception &e)
    {
        Logger::log("[INFO] Power up has no time limit");
    }
    return false;
}

void PowerUp::stop_fall() noexcept { is_falling_ = false; }