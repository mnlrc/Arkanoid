/**
 * @file laser.hpp
 * @author Manuel Rocca
 * @brief Header file for the Laser class
 * @date 2025
 *
 */

#ifndef LASER_HPP
#define LASER_HPP

// #### Internal inclusions ####
#include "rectangle.hpp"
#include "../../global_variables.hpp"

constexpr Color LASER_INNER_COLOR = Color::RED;
constexpr Color LASER_OUTER_COLOR = Color::BLACK;
constexpr double LASER_WIDTH = WINDOW_WIDTH * 0.01;
constexpr double LASER_HEIGHT = WINDOW_HEIGHT * 0.1;
constexpr double LASER_Y_SPEED = -WINDOW_HEIGHT * 0.01;
constexpr double LASER_X_SPEED = 0;

class Laser final : public Rectangle
{
public:
    /**
     * @brief Construct a new Laser object
     *
     * @param center
     */
    Laser(Point center);

    /**
     * @brief Set the laser as active, set it moving
     * 
     */
    void launch() noexcept;

    /**
     * @brief Deactivate the laser, once it has hit
     * a brick, it won't hit another
     * 
     */
    void has_hit() noexcept;

    /**
     * 
     * @return true if it's launched
     * @return false otherwise
     */
    bool is_launched() const noexcept;

    /**
     * @brief Get the speed of the laser
     * 
     * @return Point 
     */
    Point get_speed() const noexcept;

    /**
     * 
     * @return true if it was used, if it has hit something
     * @return false otherwise
     */
    bool was_used() const noexcept;

private:
    bool is_active_;
    Point speed_;
    bool has_hit_;
};

#endif