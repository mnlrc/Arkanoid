/**
 * @file laser.hpp
 * @author Manuel Rocca
 * @brief Header file for the Laser class
 * @date 2025
 *
 */

#ifndef LASER_HPP
#define LASER_HPP

#include "rectangle.hpp"
#include "../../global_variables.hpp"

constexpr Color LASER_INNER_COLOR = Color::RED;
constexpr Color LASER_OUTER_COLOR = Color::BLACK;
constexpr double LASER_WIDTH = WINDOW_WIDTH * 0.01;
constexpr double LASER_HEIGHT = WINDOW_HEIGHT * 0.1;
constexpr double LASER_Y_SPEED = - WINDOW_HEIGHT * 0.01;
constexpr double LASER_X_SPEED = 0;

class Laser final : public Rectangle
{
public:
    Laser(Point center);

    ~Laser() = default;

    void launch() noexcept;

    void has_hit() noexcept;

    bool is_launched() const noexcept;

    Point get_speed() const noexcept;

    bool was_used() const noexcept;

private:
    bool is_active_;
    Point speed_;
    bool has_hit_;
};

#endif