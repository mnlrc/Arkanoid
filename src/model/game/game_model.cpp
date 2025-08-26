/**
 * @file game_model.cpp
 * @author Manuel Rocca
 * @brief Source file for the GameModel class
 * @date 2025
 *
 */

#include "game_model.hpp"

GameModel::GameModel(int level) : Model{WINDOW_WIDTH, WINDOW_HEIGHT}, end_button_{END_TEXT, Point{WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2}, WINDOW_WIDTH * 0.5, WINDOW_HEIGHT * 0.1, Color::WHITE, Color::DARK_GOLD}

{
    LevelData level_data = LevelLoader::loadLevel(level);
    if (level_data.is_empty())
    {
        Logger::log("[ERROR] Couldn't initialize level data");
        std::__throw_runtime_error("Game Data empty, wasn't initialized properly. Aborting level loading.");
    }

    int bricks_per_row = level_data.bricks_per_row;
    int bricks_per_column = level_data.bricks_per_column;

    // setting up bricks
    double brick_width = static_cast<double>(WINDOW_WIDTH) / static_cast<double>(bricks_per_row);
    double brick_height = (WINDOW_HEIGHT * 0.5) / static_cast<double>(bricks_per_column);

    double x_pos = brick_width / 2;
    double y_pos = brick_height / 2;

    for (int i = 0; i < bricks_per_column; i++)
    {
        for (int j = 0; j < bricks_per_row; j++)
        {
            Point brick_center = Point{x_pos, y_pos};
            level_data.bricks[i][j]->set_center(brick_center);
            level_data.bricks[i][j]->set_width(brick_width);
            level_data.bricks[i][j]->set_height(brick_height);
            x_pos += brick_width;
        }
        x_pos = brick_width / 2;
        y_pos += brick_height;
    }
    bricks_ = level_data.bricks;

    // setting up racket
    double width_percentage = level_data.racket->get_width_percentage();
    double racket_width = WINDOW_WIDTH * width_percentage;
    double racket_height = WINDOW_HEIGHT / 25;                            // TODO: remove magic number
    Point racket_center = Point{WINDOW_WIDTH / 2, WINDOW_HEIGHT * 0.955}; // TODO: remove magic numbers
    level_data.racket->set_center(racket_center);
    level_data.racket->set_width(racket_width);
    level_data.racket->set_height(racket_height);

    racket_ = level_data.racket;

    // setting up ball
    balls_.emplace_back();
    Point ball_center = Point{WINDOW_WIDTH / 2, WINDOW_HEIGHT * 0.895};
    Point ball_speed = Point{5, 5};
    double ball_radius = racket_height / 2;
    std::shared_ptr<Ball> ball = std::make_shared<Ball>(ball_center, ball_radius, ball_speed);
    balls_[0] = ball;

    setup_circles();
}

std::vector<std::shared_ptr<Ball>> &GameModel::get_balls() noexcept { return balls_; }

std::vector<std::vector<std::shared_ptr<Brick>>> &GameModel::get_bricks() noexcept { return bricks_; }

std::shared_ptr<Racket> GameModel::get_racket() const noexcept { return racket_; }

Score GameModel::get_current_score() const noexcept { return current_score_; }

PowerUp GameModel::get_active_power_up() noexcept { return active_power_; }

std::vector<PowerUp> &GameModel::get_falling_power_ups() noexcept { return falling_power_ups_; }

std::vector<Laser> &GameModel::get_lasers() noexcept { return lasers_; }

std::vector<std::shared_ptr<Circle>> GameModel::get_circles() const noexcept { return circles_; }

Button GameModel::get_end_button(bool is_win) noexcept
{
    if (is_win)
    {
        end_button_.set_selected_text(0); // win text
    }
    else
    {
        end_button_.set_selected_text(1); // lose text
    }
    return end_button_;
}

void GameModel::add_score(unsigned points) noexcept
{
    current_score_.add_score(points);
}

bool GameModel::life_lost() noexcept
{
    if (remaining_lives_ > 0)
    {
        remaining_lives_--;
        circles_.pop_back();
        setup_circles();
        return true;
    }
    else
    {
        Logger::log("[INFO] Game Over");
        return false;
    }
}

void GameModel::reset_ball() noexcept
{
    double new_ball_x = racket_->get_center().x_;
    Point new_ball_center = Point{new_ball_x, WINDOW_HEIGHT * 0.895};
    double ball_radius = racket_->get_height() / 2;
    std::shared_ptr<Ball> ball = std::make_shared<Ball>(new_ball_center, ball_radius, false);
    balls_.emplace_back(ball);
}

void GameModel::handle_space_input() noexcept
{
    for (auto &ball : balls_)
    {
        if (!ball->get_state())
        { // if a ball isn't moving
            ball->change_state();
            return;
        }
    }
    if (active_power_.get_power() == Power::LASER)
    {
        Laser new_laser = Laser(racket_->get_center());
        new_laser.launch();
        lasers_.push_back(new_laser);
    }
}

void GameModel::update_ball_progress(double progress)
{
    for (auto &ball : balls_)
    {
        ball->update_speed_progress(progress);
    }
}

void GameModel::activate_power_up(const PowerUp &power_up) noexcept
{
    clear_power_up(power_up);
    active_power_ = power_up;
    activate_power(active_power_.get_power());
}

void GameModel::add_falling_power_up(const PowerUp &power_up) noexcept
{
    falling_power_ups_.push_back(power_up);
}

void GameModel::setup_circles()
{
    if (!circles_.empty())
    {
        circles_.clear();
    }
    double racket_height = racket_->get_height();
    double circle_radius = racket_height / 4;
    double margin = circle_radius / 2;
    double circles_width = (circle_radius * 2) * remaining_lives_ + margin * (remaining_lives_ - 1);
    double circles_x_pos = (WINDOW_WIDTH - circles_width) / 2 + circle_radius;
    double circles_y_pos = WINDOW_HEIGHT * 0.75;

    for (int i = 0; i < remaining_lives_; i++)
    {
        circles_.emplace_back(std::make_shared<Circle>(Point{circles_x_pos, circles_y_pos}, circle_radius, Color::RED, Color::BLACK));
        circles_x_pos += (circle_radius * 2) + margin;
    }
}

void GameModel::activate_power(const Power power)
{
    switch (power)
    {
    case Power::LASER: // nothing to handle
        break;
    case Power::ENLARGE:
        enlarge_racket();
        break;
    case Power::CATCH:
        break;
    case Power::SLOW:
        slow_balls();
        break;
    case Power::STOP:
        ball_multiplier();
        break;
    case Power::PLAYER:
        add_life();
        break;
    case Power::NONE:
    default:
        break;
    }
}

void GameModel::clear_power_up(const PowerUp new_power_up)
{
    Power current_power = active_power_.get_power();
    Power new_power = new_power_up.get_power();
    switch (current_power)
    {
    case Power::LASER:
        lasers_.clear();
        break;
    case Power::ENLARGE:
        racket_->reset_width();
        break;
    case Power::CATCH: // nothing to do or handle
        break;
    case Power::SLOW:
        reset_ball_speed(new_power);
        break;
    case Power::STOP:
        clear_balls();
        break;
    case Power::PLAYER:
        life_lost();
        break;
    case Power::NONE:
    default:
        break;
    }
}

bool GameModel::current_power_stop() noexcept
{
    return active_power_.get_power() == Power::STOP && balls_.size() != 1;
}

void GameModel::add_life() noexcept
{
    remaining_lives_++;
    setup_circles();
}

void GameModel::enlarge_racket() noexcept
{
    racket_->enlarge(RACKET_ENLARGE_PERCENTAGE);
}

// void GameModel::launch_ball() noexcept
// {
//     if (!balls_.empty())
//     {
//         for (auto &ball : balls_)
//         {
//             if (!ball->get_state())
//             { // if a ball isn't moving
//                 ball->change_state();
//             }
//         }
//     }
//     else
//     {
//         Logger::log("[ERROR] No balls available to launch");
//     }
// }

void GameModel::ball_multiplier()
{
    std::shared_ptr<Ball> active_ball = balls_[0];
    Point active_center = active_ball->get_center();
    double active_radius = active_ball->get_radius();
    Point active_speed = active_ball->get_speed();
    bool active_state = active_ball->get_state();

    Point new_speed_one = Point{active_speed.x_ * -1, active_speed.y_};
    std::shared_ptr<Ball> new_ball_one = std::make_shared<Ball>(active_center, active_radius, new_speed_one, active_state);
    Point new_speed_two = Point{active_speed.x_, active_speed.y_ * -1};
    std::shared_ptr<Ball> new_ball_two = std::make_shared<Ball>(active_center, active_radius, new_speed_two, active_state);

    balls_.push_back(new_ball_one);
    balls_.push_back(new_ball_two);
}

void GameModel::clear_balls()
{
    balls_.resize(1); // keeping one ball, the first of the vector
}

void GameModel::slow_balls()
{
    for (auto &ball : balls_)
    {
        ball->apply_slow();
    }
}

void GameModel::reset_ball_speed(const Power new_power)
{
    for (auto &ball : balls_)
    {
        if (new_power != Power::SLOW)
        {
            ball->reset_speed();
        }
    }
}
