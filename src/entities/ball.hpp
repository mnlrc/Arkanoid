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

const bool DEFAULT_BALL_STATE = false;
const double DEFAULT_BALL_SPEED = 5;

class Ball
{
private:
    Point center_;
    const double radius_;
    Point speed_;
    bool isMoving;

public:
    // #### Constructor ####
    Ball(Point c, double w, Point);
    // #### Destructor ####
    ~Ball();
    // #### Getters ####
    double getRadius() const noexcept;
    Point getCenter() const noexcept;
    Point getSpeed() const noexcept;
    bool getState() const noexcept;

    // #### Setters ####
    void setCenter(const Point pt) noexcept;
    void setSpeed(const Point) noexcept;
    void changeState() noexcept;
};

#endif