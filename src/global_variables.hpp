/**
 * @file global_variables.hpp
 * @author Manuel Rocca
 * @brief Header file that contains global variables
 * @date 2024
 *
 */

#ifndef GLOBAL_VARIABLES_HPP
#define GLOBAL_VARIABLES_HPP

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 700

enum class Direction : int
{
    LEFT = 0,
    RIGHT,
};

enum class Color : int
{
    WHITE = 0,
    BLACK,
    GREY,
    RED,
    YELLOW,
    SILVER,
    ORANGE,
    CYAN,
    GREEN,
    MAGENTA,
    BLUE,
    GOLD,
    DARK_GOLD,
    NONE, // represents an empty brick
    // ...
};

enum class UpdateResponse : int
{
    NONE = 0,
    CONTINUE,
    GAME_OVER,
    GAME_WON,
};

enum class InputResponse : int
{
    QUIT = 0,
    ENTER,
    NONE,
};

#endif
