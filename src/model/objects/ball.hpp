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

const bool DEFAULT_BALL_STATE = false;
const double DEFAULT_BALL_SPEED = 5;

class Ball : public Circle
{
public:
    // #### Constructor ####
    Ball(Point &center, double &radius, Point &speed);

    Ball(Point center, double radius, bool state);

    Ball() = default;

    // #### Destructor ####
    ~Ball() = default;

    // #### Getters ####
    Point get_speed() const noexcept;

    bool get_state() const noexcept;

    // #### Setters ####
    void set_speed(const Point &new_speed) noexcept;
    
    void change_state() noexcept;

private:
    Point speed_;
    bool is_moving_;
};

#endif