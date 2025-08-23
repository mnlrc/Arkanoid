/**
 * @file brick.cpp
 * @author Manuel Rocca
 * @brief Source file for the Brick class
 * @date 2024
 *
 */

#include "brick.hpp"
#include <iostream>
using namespace std;
Brick::Brick(Color &color, Power &power_up) : Rectangle{color, determine_outer_color(color)}, power_up_(power_up), points_(COLOR_SCORE.at(color))
{
    if (color == Color::NONE)
    {
        broken_ = true;
    }
    if (color == Color::GOLD)
        hp_ = GOLD_HP;
    if (color == Color::SILVER)
        hp_ = SILVER_HP;
    else
        hp_ = DEFAULT_HP;
}

bool Brick::is_broken() const noexcept { return broken_; };

int Brick::get_hp() const noexcept { return hp_; };

Power Brick::get_power_up() const noexcept { return power_up_; };

const int Brick::get_points() const noexcept { return points_; };

bool Brick::hit() noexcept
{
    if (inner_color_ == Color::GOLD)
    {
        return false;
    }
    if (hp_ > 1)
    {
        hp_--;
        if (inner_color_ == Color::SILVER)
        {
            outer_color_ = Color::WHITE; // changing color to show damage
        }
        return false; // signaling that the brick isn't broken yet
    }
    else
    {
        broken_ = true;
        return true; // signaling that the brick is now broken
    }
}

Color Brick::determine_outer_color(Color color) const noexcept
{
    if (color == Color::GOLD)
        return Color::DARK_GOLD;
    if (color == Color::SILVER)
        return Color::BLACK;
    else
        return Color::BLACK;
}
