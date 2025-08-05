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
#include <vector>

#include "model/objects/ball.hpp"
#include "model/objects/brick.hpp"
#include "model/objects/point.hpp"
#include "model/objects/racket.hpp"

#include "model/main_menu/menu_model.hpp"
#include "model/model.hpp"
#include "tests/allegro_test.hpp"
#include "../log/logger.hpp"

#include "global_variables.hpp"

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

    // Draw methods
    /**
     * @brief
     *
     * @param model
     */
    void draw(MenuModel &model);
    // void drawAll(const Racket &racket, const std::vector<Ball> &balls, const std::vector<std::vector<Brick>> &bricks);
    // void draw(const Racket &racket);
    // void draw(const std::vector<Ball> &balls);
    // void draw(const std::vector<std::vector<Brick>> &bricks);

private:
    ALLEGRO_DISPLAY *display_ = nullptr;
    // void drawRacket(const Racket &racket);
    // void drawBricks(const std::vector<std::vector<Brick>> &bricks);
    // void drawBall(const std::vector<Ball> &balls);

    /**
     * @brief 
     * 
     * @param color 
     * @return ALLEGRO_COLOR 
     */
    ALLEGRO_COLOR colorConvertor(Color color);
};

#endif