/**
 * @file view.hpp
 * @author Manuel Rocca
 * @brief Header file for the View class
 * @date 2024
 *
 */

#ifndef VIEW_HPP
#define VIEW_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <vector>

#include "model/objects/ball.hpp"
#include "model/objects/brick.hpp"
#include "model/objects/point.hpp"
#include "model/objects/racket.hpp"

#include "model/main_menu/menu_model.hpp"
#include "model/game/game_model.hpp"
#include "model/model.hpp"
#include "tests/allegro_test.hpp"
#include "../log/logger.hpp"

#include "global_variables.hpp"

const ALLEGRO_COLOR COLOR_WHITE = al_map_rgb(255, 255, 255);
const ALLEGRO_COLOR COLOR_BLACK = al_map_rgb(0, 0, 0);
const ALLEGRO_COLOR COLOR_GREY = al_map_rgb(200, 200, 200);
const ALLEGRO_COLOR COLOR_RED = al_map_rgb(255, 0, 0);
const ALLEGRO_COLOR COLOR_YELLOW = al_map_rgb(255, 255, 0);
const ALLEGRO_COLOR COLOR_SILVER = al_map_rgb(192, 192, 192);
const ALLEGRO_COLOR COLOR_ORANGE = al_map_rgb(255, 165, 0);
const ALLEGRO_COLOR COLOR_CYAN = al_map_rgb(0, 255, 255);
const ALLEGRO_COLOR COLOR_GREEN = al_map_rgb(0, 255, 0);
const ALLEGRO_COLOR COLOR_MAGENTA = al_map_rgb(255, 0, 255);
const ALLEGRO_COLOR COLOR_BLUE = al_map_rgb(0, 0, 255);
const ALLEGRO_COLOR COLOR_GOLD = al_map_rgb(255, 215, 0);
const ALLEGRO_COLOR COLOR_DARK_GOLD = al_map_rgb(204, 204, 0);
const ALLEGRO_COLOR COLOR_PINK = al_map_rgb(200, 150, 167);
const ALLEGRO_COLOR COLOR_DARK_GREY = al_map_rgb(34, 34, 34);

class View
{
public:
    /**
     * @brief Construct a new View object
     *
     */
    View(const int width, const int height);

    /**
     * @brief Default constructor for the View
     *
     */
    View() = default;

    /**
     * @brief Destroy the View object
     *
     */
    ~View();

    /**
     * @brief
     *
     * @param width
     * @param height
     */
    void setupAllegro(const int width, const int height);

    /**
     * @brief Get the Display object
     *
     * @return ALLEGRO_DISPLAY*
     */
    ALLEGRO_DISPLAY *getDisplay() const noexcept;

    void render_menu_model(const std::unique_ptr<MenuModel> &model);

    void render_game_model(const std::unique_ptr<GameModel> &game_model);

    void render_button(const Button &button);

private:
    ALLEGRO_DISPLAY *display_;
    ALLEGRO_FONT *font_;
    const int FONT_SIZE = 20;

    void draw_window(const Model &model);

    /**
     * @brief
     *
     * @param model
     */
    void draw(const std::unique_ptr<MenuModel> &model);

    /**
     * @brief
     *
     * @param game_model
     */
    void draw(const std::unique_ptr<GameModel> &game_model);

    void draw(const Button &button);

    void draw(const Rectangle &rectangle);

    void draw(const Circle &circle);

    void draw(Point &center, std::string &text, Color &color);

    /**
     * @brief
     *
     * @param color
     * @return ALLEGRO_COLOR
     */
    ALLEGRO_COLOR color_convertor(Color color);
};

#endif