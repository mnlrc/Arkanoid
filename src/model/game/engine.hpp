/**
 * @file engine.hpp
 * @author Manuel Rocca
 * @brief Header file for the Engine class
 * @date 2024
 *
 */

#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <vector>
#include <cmath>
#include <limits>

#include "model/objects/ball.hpp"
#include "model/objects/brick.hpp"
#include "model/objects/point.hpp"
#include "model/objects/racket.hpp"
#include "tests/allegro_test.hpp"
#include "global_variables.hpp"

enum class Direction : int
{
    LEFT = 0,
    RIGHT,
};

/**
 * @brief The Engine class manages the collisions and movement.
 *
 */
class Engine
{
public:
    /**
     * @brief Construct a new Engine object
     *
     */
    Engine() = default;

    /**
     * @brief Destroy the Engine object
     *
     */
    ~Engine() = default;

    void move(Racket &racket, Direction direction);
    void move(std::vector<Ball> &balls, Racket &racket, std::vector<std::vector<Brick>> &bricks);
    void move(std::vector<Ball> &balls, Racket &racket);
    void checkWallCollision(Ball &);
    void checkRacketCollision(Ball &, Racket &);
    void checkBrickCollision(Ball &, std::vector<std::vector<Brick>> &);
    double returnAngle(double, double) const;
};

#endif