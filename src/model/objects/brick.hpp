/**
 * @file brick.hpp
 * @author Manuel Rocca
 * @brief Header file for the Brick class
 * @date 2024
 *
 */

#ifndef BRICK_HPP
#define BRICK_HPP

#include "point.hpp"
#include "rectangle.hpp"
#include "object.hpp"
#include "../../global_variables.hpp"

#include <unordered_map>
#include <limits>

const std::unordered_map<Color, const int> COLOR_SCORE = {{Color::NONE, 0},
                                                          {Color::WHITE, 50},
                                                          {Color::ORANGE, 60},
                                                          {Color::CYAN, 70},
                                                          {Color::GREEN, 80},
                                                          {Color::RED, 90},
                                                          {Color::BLUE, 100},
                                                          {Color::MAGENTA, 110},
                                                          {Color::YELLOW, 120},
                                                          {Color::SILVER, 200},
                                                          {Color::GOLD, std::numeric_limits<int>::max()}};

const int DEFAULT_HP = 1;
const int SILVER_HP = 2;
const int GOLD_HP = std::numeric_limits<int>::max();

class Brick : public Rectangle
{
public:
    // #### Constructors ####
    Brick(Color &color, Power &power_up);

    // #### Destructor ####
    ~Brick() = default;

    // #### Getters ####
    bool is_broken() const noexcept;

    int get_hp() const noexcept;

    Power get_power_up() const noexcept;

    const int get_points() const noexcept;

    // #### Setters ####
    bool hit() noexcept;

private:
    bool broken_ = false;
    Power power_up_;
    const int points_;
    int hp_;

    Color determine_outer_color(Color color) const noexcept;
};

#endif