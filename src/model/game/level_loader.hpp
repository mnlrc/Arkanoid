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
#include "../../global_variables.hpp"
#include <string>
#include <vector>
#include <fstream>
#include <memory>

struct LevelData
{
    std::unique_ptr<Racket> racket;
    std::unique_ptr<Ball> ball;
    std::vector<std::unique_ptr<Brick>> bricks;
    Color background_color;
    Color line_color;
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

    static LevelData loadLevel(const std::string &path);

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
    static std::vector<std::unique_ptr<Brick>> loadBricks(std::ifstream &file);

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
};

#endif