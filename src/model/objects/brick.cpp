/**
 * @file brick.cpp
 * @author Manuel Rocca
 * @brief Source file for the Brick class
 * @date 2024
 *
 */

#include "brick.hpp"

Brick::Brick(Color &color, Power_Up &power_up) : Object{color}, power_up_(power_up), points_(COLOR_SCORE.at(color))
{
    if (color == Color::NONE)
        broken_ = true;
    if (color == Color::GOLD)
    {
        hp_ = GOLD_HP;
        outer_color_ = Color::DARK_GOLD;
    }
    if (color == Color::SILVER)
    {
        hp_ = SILVER_HP;
        outer_color_ = Color::BLACK;
    }
    else
    {
        hp_ = DEFAULT_HP;
    }
}

bool Brick::isBroken() const noexcept { return broken_; };

void Brick::setBroken() noexcept { broken_ = true; };
