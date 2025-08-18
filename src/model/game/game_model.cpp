/**
 * @file game_model.cpp
 * @author Manuel Rocca
 * @brief Source file for the GameModel class
 * @date 2025
 *
 */

#include "game_model.hpp"

GameModel::GameModel(int level) : Model{WINDOW_WIDTH, WINDOW_HEIGHT}
{
    LevelData level_data = LevelLoader::loadLevel(level);
    if (level_data.is_empty())
    {
        Logger::log("[ERROR] Couldn't initialize level data");
        std::__throw_runtime_error("Game Data empty, wasn't initialized properly. Aborting level loading.");
    }

    // setting up bricks
    double brick_width = WINDOW_WIDTH / BRICKS_PER_ROW;
    double brick_height = (WINDOW_HEIGHT * 0.5) / BRICKS_PER_COLUMN;

    double x_pos = brick_width / 2;
    double y_pos = brick_height / 2;

    for (int i = 0; i < BRICKS_PER_COLUMN; i++)
    {
        for (int j = 0; j < BRICKS_PER_ROW; j++)
        {
            Point brick_center = Point{x_pos, y_pos};
            level_data.bricks[i][j]->set_center(brick_center);
            level_data.bricks[i][j]->set_width(brick_width);
            level_data.bricks[i][j]->set_height(brick_height);
            x_pos += brick_width;
        }
        x_pos = brick_width;
        y_pos += brick_height;
    }
    bricks_ = level_data.bricks;

    // setting up racket
    double width_percentage = level_data.racket->get_width_percentage();
    double racket_width = WINDOW_WIDTH * width_percentage;
    double racket_height = WINDOW_HEIGHT / 6;                          // TODO: remove magic number
    Point racket_center = Point{WINDOW_WIDTH / 2, WINDOW_HEIGHT - 20}; // TODO: remove magic numbers
    level_data.racket->set_center(racket_center);
    level_data.racket->set_width(racket_width);
    level_data.racket->set_height(racket_height);

    racket_ = level_data.racket;

    // setting up ball
    balls_.emplace_back();
    std::shared_ptr<Ball> ball = std::make_shared<Ball>(Point{WINDOW_WIDTH / 2, WINDOW_HEIGHT - 50}, 25, Point{5, 5});
    balls_[0] = ball;
}

std::vector<std::shared_ptr<Ball>> GameModel::get_balls() const noexcept { return balls_; }

std::vector<std::vector<std::shared_ptr<Brick>>> GameModel::get_bricks() const noexcept { return bricks_; }

std::shared_ptr<Racket> GameModel::get_racket() const noexcept { return racket_; }

Score GameModel::get_current_score() const noexcept { return current_score_; }