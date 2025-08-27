/**
 * @file game_model.hpp
 * @author Manuel Rocca
 * @brief Header file for the GameModel class
 * @date 2025
 *
 */

#ifndef GAME_MODEL_HPP
#define GAME_MODEL_HPP

#define DEFAULT_LIVES 3

// #### Internal includes ####
#include "../objects/ball.hpp"
#include "../objects/brick.hpp"
#include "../objects/racket.hpp"
#include "../objects/score.hpp"
#include "../objects/circle.hpp"
#include "../objects/button.hpp"
#include "../objects/laser.hpp"
#include "../objects/power_up.hpp"
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

    std::vector<std::shared_ptr<Ball>> &get_balls() noexcept;

    std::vector<std::vector<std::shared_ptr<Brick>>> &get_bricks() noexcept;

    std::shared_ptr<Racket> get_racket() const noexcept;

    Score get_current_score() const noexcept;

    PowerUp get_active_power_up() noexcept;

    std::vector<PowerUp> &get_falling_power_ups() noexcept;

    std::vector<Laser> &get_lasers() noexcept;

    std::vector<std::shared_ptr<Circle>> get_circles() const noexcept;

    Button get_end_button(bool is_win) noexcept;

    void add_score(unsigned points) noexcept;

    bool life_lost() noexcept;

    void reset_ball() noexcept;

    void handle_space_input() noexcept;

    void update_ball_progress(double progress);

    void activate_power_up(const PowerUp &power_up) noexcept;

    void add_falling_power_up(const PowerUp &power_up) noexcept;

    bool current_power_stop() noexcept;

private:
    std::vector<std::shared_ptr<Ball>> balls_;
    std::vector<std::vector<std::shared_ptr<Brick>>> bricks_;
    std::shared_ptr<Racket> racket_;
    Score current_score_;
    std::vector<std::shared_ptr<Circle>> circles_; // representing lives
    int remaining_lives_ = DEFAULT_LIVES;

    std::vector<PowerUp> falling_power_ups_;
    PowerUp active_power_;
    std::vector<Laser> lasers_;

    Color background_color_;
    Color line_color_;

    Button end_button_; // idx 0 is the win text, idx 1 is the lose text

    void setup_circles();

    void activate_power(const Power power);

    void clear_power_up(const PowerUp new_power_up);

    void add_life() noexcept;

    void enlarge_racket() noexcept;

    void launch_balls(const Power new_power) noexcept;

    void ball_multiplier();

    void clear_balls();

    void slow_balls();

    void reset_ball_speed(const Power new_power);
};

#endif