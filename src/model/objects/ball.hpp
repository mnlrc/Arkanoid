/**
 * @file ball.hpp
 * @author Manuel Rocca
 * @brief Header file for the Ball class
 * @date 2024
 *
 */

#ifndef BALL_HPP
#define BALL_HPP

#include "point.hpp"
#include "circle.hpp"

#include <cmath>

const bool DEFAULT_BALL_STATE = false;
const double DEFAULT_BALL_SPEED = 5.0;
const double SLOW_FACTOR = 0.5;

class Ball : public Circle
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

    bool get_state() const noexcept;

    void reset_speed() noexcept;

    // #### Setters ####
    void set_speed(const Point &new_speed) noexcept;

    void change_state() noexcept;

    void apply_slow() noexcept;

    void update_speed_progress(double progress) noexcept;

private:
    Point speed_;
    bool is_moving_;
    Point default_ball_speed_;
    double current_slow_factor_ = 1.0;
};

#endif