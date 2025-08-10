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

enum class ModelType : int
{
    MAIN_MENU_MODEL = 0,
    GAME_MODEL,
    PAUSE_MENU_MODEL,
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

enum class Power_Up : int
{
    LASER = 0, // shoot lasers from the racket
    ENLARGE, // enlarge the rackets width
    CATCH, // catch ball when it hits the racket
    SLOW, // slow the balls travel speed
    STOP, // ball multiplier
    PLAYER, // add life
    NONE,
};

#endif
