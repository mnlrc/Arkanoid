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
    double racket_height = WINDOW_HEIGHT / 20;                            // TODO: remove magic number
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

std::vector<std::shared_ptr<Ball>> &GameModel::get_balls() noexcept { return balls_; }

std::vector<std::vector<std::shared_ptr<Brick>>> &GameModel::get_bricks() noexcept { return bricks_; }

std::shared_ptr<Racket> GameModel::get_racket() const noexcept { return racket_; }

Score GameModel::get_current_score() const noexcept { return current_score_; }

void GameModel::add_score(unsigned points) noexcept
{
    current_score_.add_score(points);
}

std::vector<std::shared_ptr<Circle>> GameModel::get_circles() const noexcept { return circles_; }

bool GameModel::life_lost() noexcept
{
    if (remaining_lives_ > 0)
    {
        remaining_lives_--;
        circles_.pop_back();
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

void GameModel::launch_ball() noexcept
{
    if (!balls_.empty())
    {
        for (auto &ball : balls_)
        {
            if (!ball->get_state())
            { // if a ball isn't moving
                ball->change_state();
            }
        }
    }
    else
    {
        Logger::log("[ERROR] No balls available to launch");
    }
}

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