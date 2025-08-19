/**
 * @file game_model.hpp
 * @author Manuel Rocca
 * @brief Header file for the GameModel class
 * @date 2025
 *
 */

#ifndef GAME_MODEL_HPP
#define GAME_MODEL_HPP

#define BRICKS_PER_ROW 14
#define BRICKS_PER_COLUMN 8

// #### Internal includes ####
#include "../objects/ball.hpp"
#include "../objects/brick.hpp"
#include "../objects/racket.hpp"
#include "../objects/score.hpp"
#include "../model.hpp"
#include "level_loader.hpp"

// #### Includes ####
#include <vector>
#include <memory>

/**
 * @brief Class that centralizes objects of the model
 * for a better management.
 *
 */
class GameModel : public Model
{
public:
    /**
     * @brief Construct a new Game Model object
     *
     */
    GameModel(int level);

    /**
     * @brief Destroy the Game Model object
     *
     */
    ~GameModel() = default;

    std::vector<std::shared_ptr<Ball>> get_balls() const noexcept;
    std::vector<std::vector<std::shared_ptr<Brick>>> get_bricks() const noexcept;
    std::shared_ptr<Racket> get_racket() const noexcept;
    Score get_current_score() const noexcept;

private:
    std::vector<std::shared_ptr<Ball>> balls_;
    std::vector<std::vector<std::shared_ptr<Brick>>> bricks_;
    std::shared_ptr<Racket> racket_;
    Score current_score_;

    Color background_color_;
    Color line_color_;
};

#endif