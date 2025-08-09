/**
 * @file model.hpp
 * @author Manuel Rocca
 * @brief Header file for the GameModel class
 * @date 2025
 *
 */

#ifndef GAME_MODEL_HPP
#define GAME_MODEL_HPP

// #### Internal includes ####
#include "../objects/ball.hpp"
#include "../objects/brick.hpp"
#include "../objects/racket.hpp"
#include "../objects/score.hpp"

// #### Includes ####
#include <vector>

/**
 * @brief Class that centralizes objects of the model
 * for a better management.
 *
 */
class GameModel
{
private:
    Ball balls_[3];
    std::vector<Brick> bricks_;
    Racket racket_;
    Score current_score_;

public:
    GameModel();
    ~GameModel();
};

#endif