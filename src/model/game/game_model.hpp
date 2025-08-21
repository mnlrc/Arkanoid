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
#define DEFAULT_LIVES 3

// #### Internal includes ####
#include "../objects/ball.hpp"
#include "../objects/brick.hpp"
#include "../objects/racket.hpp"
#include "../objects/score.hpp"
#include "../objects/circle.hpp"
#include "../objects/button.hpp"
#include "../model.hpp"
#include "level_loader.hpp"

// #### Includes ####
#include <vector>
#include <memory>
#include <string>

const std::string WIN_STRING = "You won !";
const std::string LOSE_STRING = "You lost !";

const Text WIN_TEXT = Text{WIN_STRING, Color::GREEN};
const Text LOSE_TEXT = Text{LOSE_STRING, Color::RED};

const std::vector<Text> END_TEXT = {WIN_TEXT, LOSE_TEXT};

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
    void add_score(unsigned points) noexcept;
    std::vector<std::shared_ptr<Circle>> get_circles() const noexcept;

    bool life_lost() noexcept;

    void reset_ball() noexcept;

    void launch_ball() noexcept;

    Button get_end_button(bool is_win) noexcept;

private:
    std::vector<std::shared_ptr<Ball>> balls_;
    std::vector<std::vector<std::shared_ptr<Brick>>> bricks_;
    std::shared_ptr<Racket> racket_;
    Score current_score_;
    std::vector<std::shared_ptr<Circle>> circles_; // representing lives
    int remaining_lives_ = DEFAULT_LIVES;

    Color background_color_;
    Color line_color_;

    Button end_button_; // idx 0 is the win text, idx 1 is the lose text
};

#endif