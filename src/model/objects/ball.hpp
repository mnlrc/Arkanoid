/**
 * @file ball.hpp
 * @author Manuel Rocca
 * @brief Header file for the Ball class
 * @date 2025
 *
 */

#ifndef BALL_HPP
#define BALL_HPP

#include "point.hpp"
#include "circle.hpp"
#include "../../log/logger.hpp"

#include <cmath>
#include <chrono>

constexpr bool DEFAULT_BALL_STATE = false;
constexpr double DEFAULT_BALL_SPEED = 5.0;
constexpr double SLOW_FACTOR = 0.5;
constexpr int64_t MAX_TIME_ON_RACKET = 3.0;

using namespace std::chrono;

class Ball final : public Circle
{
public:
    // #### Constructor ####
    Ball(Point &center, double &radius, Point &speed);

    Ball(Point center, double radius, bool state);

    Ball(Point center, double radius, Point speed, bool state);

    Ball() = default;

    // #### Destructor ####
    ~Ball() = default;

    // #### Getters ####
    Point get_speed() const noexcept;

    bool is_moving() const noexcept;

    void reset_speed() noexcept;

    double get_shift() const noexcept;

    // #### Setters ####
    void set_speed(const Point &new_speed) noexcept;

    void set_moving() noexcept;

    void set_stop() noexcept;

    void apply_slow() noexcept;

    void update_speed_progress(double progress) noexcept;

    bool time_up() noexcept;

    void set_shift(double new_shift) noexcept;

private:
    Point speed_;
    bool is_moving_;
    Point default_ball_speed_;
    double current_slow_factor_ = 1.0;
    steady_clock::time_point time_on_racket_ = steady_clock::time_point{}; // serves as a 0,
                                                                           // to symbolize that it wasn't
                                                                           // started
    double shift_on_racket_ = 0;
};

#endif