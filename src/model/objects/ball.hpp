/**
 * @file ball.hpp
 * @author Manuel Rocca
 * @brief Header file for the Ball class
 * @date 2025
 *
 */

#ifndef BALL_HPP
#define BALL_HPP

// #### Internal inclusions ####
#include "point.hpp"
#include "circle.hpp"
#include "../../log/logger.hpp"

// #### C++ inclusions ####
#include <cmath>
#include <chrono>

constexpr bool DEFAULT_BALL_STATE = false;
constexpr double DEFAULT_BALL_SPEED = 5.0;
constexpr double SLOW_FACTOR = 0.5; // slow percentage
constexpr int64_t MAX_TIME_ON_RACKET = 3.0;
constexpr double BALL_VERTICAL_POS = 0.895; // the percentage of the position on the window

using namespace std::chrono;

class Ball final : public Circle
{
public:
    /**
     * @brief Construct a new Ball object
     *
     */
    Ball(Point &center, double &radius, Point &speed);
    Ball(Point center, double radius, bool state);
    Ball(Point center, double radius, Point speed, bool state);
    Ball() = default;

    /**
     * @brief Get the speed of the ball
     * 
     * @return Point 
     */
    Point get_speed() const noexcept;

    /**
     * 
     * @return true if the ball is moving
     * @return false otherwise
     */
    bool is_moving() const noexcept;

    /**
     * @brief Set the speed to default speed
     * 
     */
    void reset_speed() noexcept;

    /**
     * @brief Get the shift of the ball
     * from the center of the racket
     * 
     * @return double 
     */
    double get_shift() const noexcept;


    /**
     * @brief Set the speed value of the ball
     * 
     * @param new_speed 
     */
    void set_speed(const Point &new_speed) noexcept;

    /**
     * @brief Enable ball movement
     * 
     */
    void set_moving() noexcept;

    /**
     * @brief Stop the ball
     * 
     */
    void set_stop() noexcept;

    /**
     * @brief Applies a determined slow percentage to the
     * current speed
     * 
     */
    void apply_slow() noexcept;

    /**
     * @brief Slowly regains the default speed following the progress's
     * value using linear interpolation
     * 
     * @param progress 
     */
    void update_speed_progress(double progress) noexcept;

    /**
     * 
     * @return true if the time that the ball is allowed to stay
     * on the racket is up 
     * @return false if it can stay
     */
    bool time_up() noexcept;

    /**
     * @brief Set the shift value
     * 
     * @param new_shift 
     */
    void set_shift(double new_shift) noexcept;

private:
    Point speed_;
    bool is_moving_;
    Point default_ball_speed_; // used to reset
    double current_slow_factor_ = 1.0; // percentage of slow
    steady_clock::time_point time_on_racket_ = steady_clock::time_point{}; // serves as a 0,
                                                                           // to symbolize that it wasn't
                                                                           // started
    double shift_on_racket_ = 0;
};

#endif