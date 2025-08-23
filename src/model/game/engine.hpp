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
#include <algorithm>

#include "model/objects/ball.hpp"
#include "model/objects/brick.hpp"
#include "model/objects/point.hpp"
#include "model/objects/racket.hpp"
#include "tests/allegro_test.hpp"
#include "global_variables.hpp"
#include "model/game/game_model.hpp"
#include "../../controller/game_controller.hpp"

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

    void move(std::shared_ptr<Racket> racket, Direction direction);

    UpdateResponse move(GameModel &game_model);

private:
    bool check_wall_collision(std::shared_ptr<Ball> ball);

    void check_racket_collision(std::shared_ptr<Ball> ball, std::shared_ptr<Racket> racket);

    const int check_brick_collision(std::shared_ptr<Ball> ball,
                                    std::vector<std::vector<std::shared_ptr<Brick>>> &bricks);

    double return_angle(double, double) const;

    void delete_ball(std::vector<std::shared_ptr<Ball>> &balls, const std::vector<std::shared_ptr<Ball>> &balls_to_remove);

    bool is_win(std::vector<std::vector<std::shared_ptr<Brick>>> bricks);
};

#endif