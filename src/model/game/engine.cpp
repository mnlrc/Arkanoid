/**
 * @file engine.cpp
 * @author Manuel Rocca
 * @brief Source file for the Engine class
 * @date 2025
 *
 */

#include "engine.hpp"

void Engine::move(std::shared_ptr<Racket> racket, Direction direction)
{
    double y = racket->get_center().y_;
    double new_x;
    switch (direction)
    {
    case Direction::RIGHT:
    {
        new_x = racket->get_center().x_ + racket->get_speed();
        break;
    }

    case Direction::LEFT:
    {
        new_x = racket->get_center().x_ - racket->get_speed();
        break;
    }
    default:
        new_x = WINDOW_WIDTH / 2;
        Logger::log("[ERROR] Unknown direction");
        break;
    }
    Point new_center = Point{new_x, y};
    racket->set_center(new_center);
}

void Engine::move(double mouse_x_position, GameModel &game_model) noexcept
{
    std::shared_ptr<Racket> racket = game_model.get_racket();
    Point new_center = Point{mouse_x_position, racket->get_center().y_};
    racket->set_center(new_center);
}

UpdateResponse Engine::update_model(GameModel &game_model)
{
    std::vector<std::vector<std::shared_ptr<Brick>>> &bricks = game_model.get_bricks();

    // checking win condition
    if (is_win(bricks))
    {
        return UpdateResponse::GAME_WON;
    }

    // handle power ups
    handle_power_up(game_model);

    std::vector<std::shared_ptr<Ball>> &balls = game_model.get_balls();
    std::shared_ptr<Racket> racket = game_model.get_racket();

    // updating ball positions
    size_t size = balls.size();
    size_t temp_size = size;
    std::vector<std::shared_ptr<Ball>> balls_to_remove;
    for (size_t i = 0; i < size; i++)
    {
        std::shared_ptr<Ball> ball = balls[i];
        if (!ball->is_moving())
        {
            if (ball->time_up())
            {
                ball->set_moving();
            }
            else
            {                                          // updating the position to follow the racket
                double ball_shift = ball->get_shift(); // TODO: add this to a methode "track racket"
                double racket_center_x = racket->get_center().x_;
                Point ball_center = Point{racket_center_x + ball_shift, ball->get_center().y_};
                ball->set_center(ball_center);
                continue; // ball is not moving, skip it
            }
        }
        else
        {
            check_racket_collision(game_model, ball);
        }
        if (check_wall_collision(ball))
        {
            if (temp_size == 1)
            {
                // manage life loss and/or game over
                if (game_model.life_lost())
                {
                    game_model.reset_ball();
                    return UpdateResponse::CONTINUE;
                }
                else // game over
                {
                    return UpdateResponse::GAME_OVER;
                }
            }
            else
            {
                temp_size--;
                balls_to_remove.push_back(ball);
                continue;
            }
        }

        // checking brick collision
        game_model.add_score(check_brick_collision(ball, game_model));

        // updating ball position
        double x_pos = ball->get_center().x_;
        double y_pos = ball->get_center().y_;

        double x_speed = ball->get_speed().x_;
        double y_speed = ball->get_speed().y_;

        ball->set_center({x_pos + x_speed, y_pos + y_speed});
    }

    // removing balls that are out of bounds
    if (!balls_to_remove.empty())
    {
        delete_ball(balls, balls_to_remove);
    }

    handle_falling_power_ups(game_model);

    if (game_model.get_active_power_up().get_power() == Power::LASER)
    {
        std::vector<Laser> &lasers = game_model.get_lasers();
        for (auto &laser : lasers)
        {
            if (!laser.is_launched()) // the lasers are activated from idx 0 to 1000
            {                         // so if we run into a laser that isn't launched
                                      // we don't need to check the rest
                break;
            }
            if (laser.was_used())
            {
                continue;
            }
            Point previous_center = laser.get_center();
            Point laser_speed = laser.get_speed();
            Point new_center = Point{previous_center.x_, previous_center.y_ + laser_speed.y_};
            laser.set_center(new_center);
            game_model.add_score(check_laser_collision(laser, game_model));
        }
    }

    return UpdateResponse::CONTINUE;
}

void Engine::handle_falling_power_ups(GameModel &game_model)
{
    const int FALLING_SPEED = 3; // TODO: set as global variable
    std::vector<PowerUp> &power_ups = game_model.get_falling_power_ups();

    if (power_ups.empty())
    {
        return;
    }

    for (auto &power_up : power_ups)
    {
        if (power_up.is_falling() && !power_up.is_active())
        {
            Point current_center = power_up.get_center();
            power_up.set_center(Point{current_center.x_, current_center.y_ + FALLING_SPEED});
        }
    }
    check_power_up_collision(game_model);
}

bool Engine::check_wall_collision(std::shared_ptr<Ball> ball)
{
    const double BALL_RADIUS = ball->get_radius();
    const double TOP = BALL_RADIUS;
    const double BOTTOM = WINDOW_HEIGHT - BALL_RADIUS;
    const double LEFT = BALL_RADIUS;
    const double RIGHT = WINDOW_WIDTH - BALL_RADIUS;

    bool is_out = false;

    // resetting ball position after every bounce to assure it doesn't go out of bounds
    if (ball->get_center().x_ >= RIGHT)
    {
        ball->set_speed({ball->get_speed().x_ * -1, ball->get_speed().y_});
        ball->set_center({RIGHT, ball->get_center().y_});
    }

    else if (ball->get_center().x_ <= LEFT)
    {
        ball->set_speed({ball->get_speed().x_ * -1, ball->get_speed().y_});
        ball->set_center({LEFT, ball->get_center().y_});
    }

    else if (ball->get_center().y_ >= BOTTOM)
    {
        is_out = true;
    }

    else if (ball->get_center().y_ <= TOP)
    {
        ball->set_speed({ball->get_speed().x_, ball->get_speed().y_ * -1});
        ball->set_center({ball->get_center().x_, TOP});
    }
    return is_out;
}

void Engine::check_racket_collision(GameModel &game_model, std::shared_ptr<Ball> ball)
{
    std::shared_ptr<Racket> racket = game_model.get_racket();

    const double RACKET_TOP = racket->get_top();
    const double RACKET_LEFT = racket->get_left();
    const double RACKET_RIGHT = racket->get_right();

    if ( // Vertical collision
        ball->get_center().y_ + ball->get_radius() >= RACKET_TOP &&
        ball->get_center().y_ - ball->get_radius() <= RACKET_TOP &&
        // Horizontal collision
        ball->get_center().x_ >= RACKET_LEFT &&
        ball->get_center().x_ <= RACKET_RIGHT)
    {

        ball->set_center({ball->get_center().x_, RACKET_TOP - ball->get_radius()});

        double ball_shift = ball->get_center().x_ - RACKET_LEFT; // used to calculate the bounce angle
        double angle = return_angle(ball_shift, racket->get_width());
        double speed = sqrt(pow(ball->get_speed().x_, 2) + pow(ball->get_speed().y_, 2));
        double x_speed = cos(angle);
        double y_speed = -sin(angle);
        ball->set_speed({x_speed * speed, y_speed * speed});

        if (game_model.get_active_power_up().get_power() == Power::CATCH)
        {
            // the distance of the ball from the center of the racket
            double delta = ball->get_center().x_ - racket->get_center().x_;
            ball->set_stop(); // stopping the ball and starting the timer
            ball->set_shift(delta);
        }
    }
}

int Engine::check_brick_collision(std::shared_ptr<Ball> ball,
                                  GameModel &game_model)
{
    double C_X = ball->get_center().x_;
    double C_Y = ball->get_center().y_;
    double RADIUS = ball->get_radius();
    std::vector<std::vector<std::shared_ptr<Brick>>> &bricks = game_model.get_bricks();

    for (auto &brick_row : bricks)
    {
        for (auto &brick : brick_row)
        {
            if (brick->is_broken())
            {
                continue;
            }

            // defining brick limits for clearer code
            double LEFT = brick->get_left();
            double RIGHT = brick->get_right();
            double TOP = brick->get_top();
            double BOTTOM = brick->get_bottom();

            if ((C_X + RADIUS > LEFT && C_X - RADIUS < RIGHT) &&
                (C_Y + RADIUS > TOP && C_Y - RADIUS < BOTTOM))
            {
                // calculating side of collision
                double overlap_x = std::min(C_X + RADIUS - LEFT, RIGHT - (C_X - RADIUS));
                double overlap_y = std::min(C_Y + RADIUS - TOP, BOTTOM - (C_Y - RADIUS));

                if (overlap_x < overlap_y)
                {
                    ball->set_speed({ball->get_speed().x_ * -1, ball->get_speed().y_});
                    if (C_X < brick->get_center().x_)
                    {
                        ball->set_center({LEFT - RADIUS, C_Y});
                    }
                    else
                    {
                        ball->set_center({RIGHT + RADIUS, C_Y});
                    }
                }
                else
                {
                    ball->set_speed({ball->get_speed().x_, ball->get_speed().y_ * -1});
                    if (C_Y < brick->get_center().y_)
                    {
                        ball->set_center({C_X, TOP - RADIUS});
                    }
                    else
                    {
                        ball->set_center({C_X, BOTTOM + RADIUS});
                    }
                }

                // update brick state
                if (brick->hit()) // brick was broken
                {
                    return brick_hit(game_model, brick);
                }
                return 0; // no brick was broken
            }
        }
    }
    return 0; // no collision
}

void Engine::check_power_up_collision(GameModel &game_model)
{
    std::shared_ptr<Racket> racket = game_model.get_racket();
    std::vector<PowerUp> &power_ups = game_model.get_falling_power_ups();

    const double RACKET_TOP = racket->get_top();
    const double RACKET_LEFT = racket->get_left();
    const double RACKET_RIGHT = racket->get_right();

    for (auto &power_up : power_ups)
    {
        if (power_up.is_falling()) // verification
        {
            const double POWER_UP_BOTTOM = power_up.get_bottom();
            const double POWER_UP_LEFT = power_up.get_left();
            const double POWER_UP_RIGHT = power_up.get_right();
            const double POWER_UP_TOP = power_up.get_top();

            if (POWER_UP_BOTTOM >= RACKET_TOP &&                               // vertical collision
                POWER_UP_RIGHT >= RACKET_LEFT && POWER_UP_LEFT <= RACKET_RIGHT // horizontal collision
            )
            {
                power_up.activate();
                game_model.activate_power_up(power_up);
            }
            if (POWER_UP_TOP >= WINDOW_HEIGHT)
            {
                power_up.stop_fall();
            }
        }
    }
}

int Engine::check_laser_collision(Laser &laser, GameModel &game_model)
{
    std::vector<std::vector<std::shared_ptr<Brick>>> &bricks = game_model.get_bricks();

    for (auto &brick_row : bricks)
    {
        for (auto &brick : brick_row)
        {
            double BRICK_LEFT = brick->get_left();
            double BRICK_RIGHT = brick->get_right();
            double BRICK_BOTTOM = brick->get_bottom();

            double LASER_LEFT = laser.get_left();
            double LASER_RIGHT = laser.get_right();
            double LASER_TOP = laser.get_top();

            if (LASER_TOP <= BRICK_BOTTOM &&                              // vertical collision
                LASER_RIGHT >= BRICK_LEFT && LASER_LEFT <= BRICK_RIGHT && // horizontal collision
                !brick->is_broken())
            {
                laser.has_hit();
                if (brick->hit())
                {
                    return brick_hit(game_model, brick);
                }
                return 0;
            }
        }
    }
    return 0; // no brick was hit
}

constexpr double Engine::return_angle(double x, double L) const
{
    return ((30 + 120 * (1 - (x / L))) * (M_PI / 180)); // converting to rads
}

void Engine::delete_ball(std::vector<std::shared_ptr<Ball>> &balls, const std::vector<std::shared_ptr<Ball>> &balls_to_remove)
{ // TODO: move to game model
    for (const auto &ball : balls_to_remove)
    {
        balls.erase(std::remove(balls.begin(), balls.end(), ball), balls.end());
    }
}

bool Engine::is_win(std::vector<std::vector<std::shared_ptr<Brick>>> bricks)
{
    for (const auto &row : bricks)
    {
        for (const auto &brick : row)
        {
            if (!brick->is_broken() && brick->get_inner_color() != Color::GOLD)
            {
                return false; // if any brick is not broken, the game is not won
            }
        }
    }
    return true; // all bricks are broken, the game is won
}

void Engine::handle_power_up(GameModel &game_model)
{
    PowerUp active_power_up = game_model.get_active_power_up();
    double progress = active_power_up.progress();

    switch (active_power_up.get_power())
    {
    case Power::SLOW:
        game_model.update_ball_progress(progress);
        break;
    case Power::LASER:
    case Power::ENLARGE:
    case Power::CATCH:
    case Power::STOP:
    case Power::PLAYER:
    case Power::NONE:
    default:
        break;
    }

    if (progress >= 1.0) // time is 100% up
    {
        game_model.activate_power_up(PowerUp());
    }
}

int Engine::brick_hit(GameModel &game_model, std::shared_ptr<Brick> hit_brick)
{
    if (!game_model.current_power_stop())
    {
        Power broken_brick_power = hit_brick->get_power_up();
        if (broken_brick_power != Power::NONE)
        {
            PowerUp power_up = PowerUp{hit_brick->get_center(), broken_brick_power};
            game_model.add_falling_power_up(power_up);
        }
    }
    return hit_brick->get_points();
}