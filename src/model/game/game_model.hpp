/**
 * @file game_model.hpp
 * @author Manuel Rocca
 * @brief Header file for the GameModel class
 * @date 2025
 *
 */

#ifndef GAME_MODEL_HPP
#define GAME_MODEL_HPP

// #### Internal inclusions ####
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

// #### C++ inclusions ####
#include <vector>
#include <memory>
#include <string>

constexpr std::string WIN_STRING = "You won !";
constexpr std::string LOSE_STRING = "You lost !";
constexpr int DEFAULT_LIVES = 3;

const Text WIN_TEXT = Text{WIN_STRING, Color::GREEN};
const Text LOSE_TEXT = Text{LOSE_STRING, Color::RED};

const std::vector<Text> END_TEXT = {WIN_TEXT, LOSE_TEXT};

/**
 * @brief Class that centralizes objects of the model
 * for a better management
 *
 */
class GameModel final : public Model
{
public:
    /**
     * @brief Construct a new Game Model object
     *
     * @param level The level to load
     */
    GameModel(int level);

    /**
     * @brief Get the balls object
     *
     * @return std::vector<std::shared_ptr<Ball>>&
     */
    std::vector<std::shared_ptr<Ball>> &get_balls() noexcept;

    /**
     * @brief Get the bricks object
     *
     * @return std::vector<std::vector<std::shared_ptr<Brick>>>&
     */
    std::vector<std::vector<std::shared_ptr<Brick>>> &get_bricks() noexcept;

    /**
     * @brief Get the racket object
     *
     * @return std::shared_ptr<Racket>
     */
    std::shared_ptr<Racket> get_racket() const noexcept;

    /**
     * @brief Get the current score object
     *
     * @return Score
     */
    Score get_current_score() const noexcept;

    /**
     * @brief Get the active power up object
     *
     * @return PowerUp
     */
    PowerUp get_active_power_up() noexcept;

    /**
     * @brief Get the falling power ups object
     *
     * @return std::vector<PowerUp>&
     */
    std::vector<PowerUp> &get_falling_power_ups() noexcept;

    /**
     * @brief Get the lasers object
     *
     * @return std::vector<Laser>&
     */
    std::vector<Laser> &get_lasers() noexcept;

    /**
     * @brief Get the circles object
     *
     * @return std::vector<std::shared_ptr<Circle>>
     */
    std::vector<std::shared_ptr<Circle>> get_circles() const noexcept;

    /**
     * @brief Get the end button object
     *
     * @param is_win
     * @return Button
     */
    Button get_end_button(bool is_win) noexcept;

    /**
     * @brief Adds the points parameter to the current score
     *
     * @param points The points to add
     */
    void add_score(unsigned points) noexcept;

    /**
     * @brief Manages the loss of a life and the circles (representing the lives)
     *
     * @return true If a life is lost but wasn't the last
     * @return false No life left, game over
     */
    bool life_lost() noexcept;

    /**
     * @brief Creates a new ball stuck on the racket
     * in an immobile state
     *
     */
    void reset_ball() noexcept;

    /**
     * @brief Launches a ball on the racket if there's one stuck on it, launches
     * a laser otherwise (if the Laser power is active)
     *
     */
    void handle_space_input() noexcept;

    /**
     * @brief Updates the speed of the balls following the progress
     *
     * @param progress The progress of the time of the power up. Takes
     * a value between 0 and 1 that represents the time left for the
     * power up
     */
    void update_ball_progress(double progress);

    /**
     * @brief Manages the power up transition by cleaning up the previous one
     * and activating the new one
     *
     * @param power_up
     */
    void activate_power_up(const PowerUp &power_up) noexcept;

    /**
     * @brief Add a falling power up (not activated, that hasn't hit the racket yet)
     *
     * @param power_up
     */
    void add_falling_power_up(const PowerUp &power_up) noexcept;

    /**
     * @brief Checks if the power up STOP is still active by
     * checking the number of remaining balls
     *
     * @return true The power up is still active
     * @return false The power up is expired
     */
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

    /**
     * @brief Set the up circles object using relative positions
     * to the window borders
     *
     */
    void setup_circles();

    /**
     * @brief Manages the activation of a power, how it affects
     * the model
     *
     * @param power
     */
    void activate_power(const Power power);

    /**
     * @brief Clear the previous power up by resetting some
     * effects
     *
     * @param new_power_up Used to check some conditions because
     * some power ups can stack
     */
    void clear_power_up(const PowerUp new_power_up);

    /**
     * @brief Add a life, position the life circles
     *
     */
    void add_life() noexcept;

    /**
     * @brief Enlarge the racket
     *
     */
    void enlarge_racket() noexcept;

    /**
     * @brief Launches all the balls that are on the racket (when the
     * CATCH power up is over)
     *
     * @param new_power
     */
    void launch_balls(const Power new_power) noexcept;

    /**
     * @brief Applies the STOP power by creating two new balls
     *
     */
    void ball_multiplier();

    /**
     * @brief Delete all balls, keep one
     *
     */
    void clear_balls();

    /**
     * @brief Apply slow factor to the balls
     *
     */
    void slow_balls();

    /**
     * @brief Reset the ball speed
     *
     * @param new_power
     */
    void reset_ball_speed(const Power new_power);
};

#endif