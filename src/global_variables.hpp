/**
 * @file global_variables.hpp
 * @author Manuel Rocca
 * @brief Header file that contains global variables
 * @date 2024
 *
 */

#ifndef GLOBAL_VARIABLES_HPP
#define GLOBAL_VARIABLES_HPP

#include <allegro5/color.h>

// TODO: à déplacer dans la view, pas besoin en tant que global
const ALLEGRO_COLOR COLOR_RED = al_map_rgb(255, 0, 0);
const ALLEGRO_COLOR COLOR_GREY = al_map_rgb(200, 200, 200);
const ALLEGRO_COLOR COLOR_GREEN = al_map_rgb(0, 255, 0);
const ALLEGRO_COLOR COLOR_YELLOW = al_map_rgb(255, 255, 0);
const ALLEGRO_COLOR COLOR_BLACK = al_map_rgb(0, 0, 0);
const ALLEGRO_COLOR COLOR_WHITE = al_map_rgb(255, 255, 255);
const ALLEGRO_COLOR COLOR_PINK = al_map_rgb(200, 150, 167);
const ALLEGRO_COLOR COLOR_MAGENTA = al_map_rgb(255, 0, 255);
const ALLEGRO_COLOR COLOR_BLUE = al_map_rgb(0, 0, 255);
const ALLEGRO_COLOR COLOR_DARK_GREY = al_map_rgb(34, 34, 34);

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
    // ...
};

#endif
