/**
 * @file level_loader.cpp
 * @author Manuel Rocca
 * @brief Source file for the LevelLoader class
 * @date 2025
 *
 */

#include "level_loader.hpp"

bool LevelData::is_empty()
{
    return !racket && bricks.empty();
}

LevelData LevelLoader::loadLevel(int level)
{
    LevelData level_data;
    if (level <= 0 || level > 5)
    {
        Logger::log("[ERROR] Wrong level given to load");
        return level_data;
    }
    std::string path = LEVEL_MAP.at(level);
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

            Color racket_inner_color;
            Color racket_outer_color;
            try
            {
                getline(file, line); // getting racket inner color
                racket_inner_color = color_from_char(line[0]);
                getline(file, line); // getting racket outer color
                racket_outer_color = color_from_char(line[0]);
            }
            catch (const std::exception &e)
            {
                Logger::log("[ERROR] Exception when reading racket colors: " + std::string(e.what()));
                racket_inner_color = Color::WHITE; // setting default color: TODO: set defaults as global variables
                racket_outer_color = Color::BLACK; // setting default color
            }

            // TODO: remove magic numbers
            std::shared_ptr<Racket> temp_racket = std::make_shared<Racket>(racket_inner_color, racket_outer_color, racket_width);
            std::vector<std::vector<std::shared_ptr<Brick>>> temp_bricks = loadBricks(file, level_data);

            level_data.racket = temp_racket;
            level_data.bricks = temp_bricks;

            getline(file, line);
            Color background_color = color_from_string(line);
            getline(file, line);
            Color line_color = color_from_string(line);

            level_data.background_color = background_color;
            level_data.line_color = line_color;
        }
        else
        {
            Logger::log("[ERROR] Wrong header");
        }
    }
    else
    {
        Logger::log("[ERROR] Couldn't open file");
        exit(1);
    }

    file.close();
    return level_data;
}

bool LevelLoader::checkTag(const std::string &level_tag)
{
    return level_tag == "ARKANOID-LEVEL";
}
std::vector<std::vector<std::shared_ptr<Brick>>> LevelLoader::loadBricks(std::ifstream &file, LevelData &level_data)
{
    std::vector<std::vector<std::shared_ptr<Brick>>> bricks;
    std::string line;
    int idx = 0;
    while (getline(file, line))
    {
        if (line.empty())
        {
            break;
        }
        bricks.emplace_back();
        auto &current_row = bricks.back();
        for (size_t i = 0; i < line.length(); i += 4)
        {
            char color = line[i];
            // char dash = line[i + 1];
            char power_up = line[i + 2];
            Color brick_color = color_from_char(color);
            Power brick_power_up = power_up_from_char(power_up);
            current_row.emplace_back(std::make_shared<Brick>(brick_color, brick_power_up));
        }
        idx++;
        if (!current_row.empty())
        {
            level_data.bricks_per_row = static_cast<int>(current_row.size());
        }
    }
    level_data.bricks_per_column = idx;
    return bricks;
}

Color LevelLoader::color_from_char(const char &c)
{
    switch (c)
    {
    case 'W':
        return Color::WHITE;
    case 'Y':
        return Color::YELLOW;
    case 'M':
        return Color::MAGENTA;
    case 'B':
        return Color::BLUE;
    case 'R':
        return Color::RED;
    case 'G':
        return Color::GREEN;
    case 'C':
        return Color::CYAN;
    case 'O':
        return Color::ORANGE;
    case 'S':
        return Color::SILVER;
    case 'I': // I as infinite for infinite hp
        return Color::GOLD;
    case '_':
        return Color::NONE;
    default:
        Logger::log("[ERROR] Unknown color when reading level file");
        return Color::BLACK; // using black as default because of RGB values being 0, 0, 0
    }
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

Power LevelLoader::power_up_from_char(const char &c)
{
    switch (c)
    {
    case 'L':
        return Power::LASER;
    case 'E':
        return Power::ENLARGE;
    case 'C':
        return Power::CATCH;
    case 'S':
        return Power::SLOW;
    case 'M': // 'M' referencing multiply because this power up multiplies the number of balls
        return Power::STOP;
    case 'P':
        return Power::PLAYER;
    default:
        return Power::NONE;
    }
}