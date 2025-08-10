/**
 * @file level_loader.cpp
 * @author Manuel Rocca
 * @brief Source file for the LevelLoader class
 * @date 2025
 *
 */

#include "level_loader.hpp"

LevelData LevelLoader::loadLevel(const std::string &path)
{
    LevelData level_data;
    std::ifstream file;
    file.open(path);

    std::string line;
    if (file.is_open())
    {
        getline(file, line); // getting tag
        if (checkTag(line))
        {
            getline(file, line); // getting racket width value
            double racket_width;
            try
            {
                racket_width = std::stod(line);
            }
            catch (int error)
            {
                Logger::log("[ERROR] Conversion error for racket size, error code: " + std::to_string(error));
                racket_width = 0.25; // setting racket size to an arbitrary value TODO magic numbers
            }
            // TODO: remove magic numbers
            std::unique_ptr<Racket> temp_racket = std::make_unique<Racket>(Point{WINDOW_WIDTH / 2, WINDOW_HEIGHT - 20}, // TODO: temp
                                                                           WINDOW_WIDTH * racket_width,
                                                                           WINDOW_HEIGHT * 0.15,
                                                                           10);
            std::unique_ptr<Ball> temp_ball = std::make_unique<Ball>(Point{WINDOW_WIDTH / 2, WINDOW_HEIGHT - 55},
                                                                     25,
                                                                     Point{DEFAULT_BALL_SPEED, DEFAULT_BALL_SPEED});
            std::vector<std::unique_ptr<Brick>> temp_bricks = loadBricks(file);

            level_data.racket = std::move(temp_racket);
            level_data.ball = std::move(temp_ball);
            level_data.bricks = std::move(temp_bricks);
        }
        else
        {
            Logger::log("[ERROR] Wrong header");
        }
    }
    else
    {
        Logger::log("[ERROR] Couldn't open file");
    }

    file.close();
    return level_data;
}

bool LevelLoader::checkTag(const std::string &level_tag)
{
    return level_tag == "ARKANOID-LEVEL";
}

std::vector<std::unique_ptr<Brick>> LevelLoader::loadBricks(std::ifstream &file)
{
    std::vector<std::unique_ptr<Brick>> bricks;
    double brick_width = WINDOW_WIDTH / 14;
    double brick_height = (WINDOW_HEIGHT * 0.5) / 10;
    double x_pos = brick_width / 2;
    double y_pos = brick_height / 2;

    std::string line;
    while (getline(file, line))
    {
        if (line.empty())
        {
            break;
        }

        for (size_t i = 0; i < line.length(); i += 4)
        {
            // char color = line[i]; // TODO: add color
            // char dash = line[i + 1];
            // char power_up = line[i + 2]; // TODO: add powerup
            // if (color != '_')
            // {
            bricks.emplace_back(std::make_unique<Brick>(Point{x_pos, y_pos}, brick_width, brick_height, true));
            // }
            x_pos += brick_width;
        }
        x_pos = brick_width;
        y_pos += brick_height;
    }
    return bricks;
}

Color LevelLoader::color_from_char(const char &c)
{
    switch (c)
    {
    case 'Y':
        return Color::YELLOW;
        break;
    case 'M':
        // return Color::MAGENTA;
        break;
    case 'B':
        // return Color::BLUE;
        break;
    case 'R':
        return Color::RED;
        break;
    case 'G':
        // return Color::GREEN;
        break;
    case 'C':
        // return Color::CYAN;
        break;
    case 'O':
        // return Color::ORANGE;
        break;
    case 'W':
        return Color::WHITE;
        break;
    default:
        Logger::log("[ERROR] Unknown color when reading level file");
        return Color::BLACK; // using black as default because of RGB values being 0, 0, 0
        break;
    }
    return Color::BLACK; // temp
}

Color LevelLoader::color_from_string(const std::string &str)
{
    if (str.compare("GREY"))
        return Color::GREY;
    if (str.compare("BLACK"))
        return Color::BLACK;
    if (str.compare("WHITE"))
        return Color::WHITE;
    return Color::BLACK; // using black as default because of RGB values being 0, 0, 0
}
