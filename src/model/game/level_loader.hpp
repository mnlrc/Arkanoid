/**
 * @file level_loader.hpp
 * @author Manuel Rocca
 * @brief Header file for the LevelLoader class
 * @date 2025
 *
 */

#ifndef LEVEL_LOADER_HPP
#define LEVEL_LOADER_HPP

#include "../objects/ball.hpp"
#include "../objects/racket.hpp"
#include "../objects/brick.hpp"
#include "../../log/logger.hpp"
#include "../objects/power_up.hpp"
#include "../../global_variables.hpp"
#include <string>
#include <vector>
#include <fstream>
#include <memory>
#include <unordered_map>

const std::unordered_map<int, const std::string> LEVEL_MAP = {{1, "levels/level-1.txt"},
                                                              {2, "levels/level-2.txt"},
                                                              {3, "levels/level-3.txt"},
                                                              {4, "levels/level-4.txt"},
                                                              {5, "levels/level-5.txt"}};

struct LevelData
{
    std::shared_ptr<Racket> racket;
    std::vector<std::vector<std::shared_ptr<Brick>>> bricks;
    Color background_color;
    Color line_color;
    int bricks_per_row;
    int bricks_per_column;

    /**
     * @brief
     *
     * @return true
     * @return false
     */
    bool is_empty();
};

class LevelLoader
{
public:
    /**
     * @brief Deleted constructor and destructor
     *
     */
    LevelLoader() = delete;
    ~LevelLoader() = delete;

    static LevelData loadLevel(int level);

private:
    /**
     * @brief
     *
     * @param level_tag
     * @return true
     * @return false
     */
    static bool checkTag(const std::string &level_tag);

    /**
     * @brief
     *
     * @param file
     * @return std::vector<Brick>
     */
    static std::vector<std::vector<std::shared_ptr<Brick>>> loadBricks(std::ifstream &file, LevelData &level_data);

    /**
     * @brief
     *
     * @param c
     * @return Color
     */
    static Color color_from_char(const char &c);

    /**
     * @brief
     *
     * @param str
     * @return Color
     */
    static Color color_from_string(const std::string &str);

    /**
     * @brief
     *
     * @param c
     * @return Power
     */
    static Power power_up_from_char(const char &c);
};

#endif