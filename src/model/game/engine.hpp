/**
 * @file engine.hpp
 * @author Manuel Rocca
 * @brief Header file for the Engine class
 * @date 2025
 *
 */

#ifndef ENGINE_HPP
#define ENGINE_HPP

// #### Internal inclusions ####
#include "model/objects/ball.hpp"
#include "model/objects/brick.hpp"
#include "model/objects/point.hpp"
#include "model/objects/racket.hpp"
#include "tests/allegro_test.hpp"
#include "global_variables.hpp"
#include "model/game/game_model.hpp"
#include "../../controller/game_controller.hpp"

// #### C++ inclusions ####
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

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

    /**
     * @brief Moves the racket in the selected direction by using its speed
     *
     * @param racket The racket to move
     * @param direction The direction in which it's moved
     */
    void move(std::shared_ptr<Racket> racket, Direction direction);

    /**
     * @brief Moves the racket following the mouse's position
     *
     * @param mouse_x_position The position of the mouse
     * @param game_model The game model used to update
     */
    void move(double mouse_x_position, GameModel &game_model) noexcept;

    /**
     * @brief Updates the model after each tic of the game
     *
     * @param game_model The game model used to update
     * @return UpdateResponse The response of the tic (if some event happened such as a win)
     */
    UpdateResponse update_model(GameModel &game_model);

private:
    /**
     * @brief Handles the movement of the power ups falling
     *
     * @param game_model
     */
    void handle_falling_power_ups(GameModel &game_model);

    /**
     * @brief Checks if there's a collision between the ball and the walls of the game
     * If there's one, it updates the speed of the ball. If the collision happens
     * at the bottom border, the ball is out
     *
     * @param ball
     * @return true If the ball has hit the bottom border
     * @return false Otherwise
     */
    bool check_wall_collision(std::shared_ptr<Ball> ball);

    /**
     * @brief Checks the collision between the ball and the racket. If the CATCH
     * power up is active, the ball's relative position to the center of the racket
     * is recorded and the ball is set not to move
     *
     * @param game_model
     * @param ball
     */
    void check_racket_collision(GameModel &game_model, std::shared_ptr<Ball> ball);

    /**
     * @brief Checking the collisions between the ball and the bricks. If a collision
     * happens, we update the brick's life and if the same brick is broken, it's
     * points are returned
     *
     * @param ball
     * @param game_model
     * @return int The points given by a broken brick. 0 if no brick was broken
     */
    int check_brick_collision(std::shared_ptr<Ball> ball,
                              GameModel &game_model);

    /**
     * @brief Checks the collision between the racket and any falling power up.
     * If a collision happens, we update the power up's state by activating it
     * and setting it as the model's active power up
     *
     * @param game_model
     */
    void check_power_up_collision(GameModel &game_model);

    /**
     * @brief Checks the collision between a moving laser and the bricks.
     * If a brick is hit, it's damaged and if it's broken it's points are
     * returned
     *
     * @param laser
     * @param game_model
     * @return int The points given by any broken brick
     */
    int check_laser_collision(Laser &laser, GameModel &game_model);

    /**
     * @brief The angle of the speed of the ball after it hits the racket
     *
     * @return constexpr double
     */
    constexpr double return_angle(double, double) const;

    /**
     * @brief Deletes the selected balls (from balls_to_remove) from the real balls vector
     *
     * @param balls
     * @param balls_to_remove
     */
    void delete_ball(std::vector<std::shared_ptr<Ball>> &balls, const std::vector<std::shared_ptr<Ball>> &balls_to_remove);

    /**
     * @brief Checks if all bricks are broken (except the golden ones)
     *
     * @param bricks
     * @return true The game is won
     * @return false All the bricks aren't broken yet
     */
    bool is_win(std::vector<std::vector<std::shared_ptr<Brick>>> bricks);

    /**
     * @brief Handles the timer aspect of the power ups and the progressive
     * events that happen during some power up's active time
     * 
     * @param game_model 
     */
    void handle_power_up(GameModel &game_model);

    /**
     * @brief Handles the point and power up retrieval from the brick by updating them
     * directly in the GameModel
     * This method mostly serves as refactoring, to avoid any code duplication
     * 
     * @param game_model 
     * @param hit_brick 
     * @return int The points given by the broken brick
     */
    int brick_hit(GameModel &game_model, std::shared_ptr<Brick> hit_brick);

    /**
     * @brief Updates the position to the ball following the racket's. Only happens
     * if the ball is on the racket
     * 
     * @param ball 
     * @param racket 
     */
    void track_racket(std::shared_ptr<Ball> ball, std::shared_ptr<Racket> racket);

    /**
     * @brief Manages the movement of the active lasers, updates their position
     * 
     * @param game_model 
     */
    void handle_laser_power_up(GameModel &game_model);
};

#endif