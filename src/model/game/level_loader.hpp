/**
 * @file level_loader.hpp
 * @author Manuel Rocca
 * @brief Header file for the LevelLoader class
 * @date 2025
 *
 */

#ifndef LEVEL_LOADER_HPP
#define LEVEL_LOADER_HPP

// #### Internal inclusions ####
#include "../objects/ball.hpp"
#include "../objects/racket.hpp"
#include "../objects/brick.hpp"
#include "../../log/logger.hpp"
#include "../objects/power_up.hpp"
#include "../../global_variables.hpp"

// #### C++ inclusions ####
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

/**
 * @brief Struct used to store the data held in the level text files
 *
 */
struct LevelData
{
    std::shared_ptr<Racket> racket;
    std::vector<std::vector<std::shared_ptr<Brick>>> bricks;
    Color background_color;
    Color line_color;
    int bricks_per_row;
    int bricks_per_column;

    /**
     * @brief Checks if the struct is empty, can happen if an error occurs when
     * reading a text file
     *
     * @return true
     * @return false
     */
    bool is_empty();
};

/**
 * @brief Static class used to load the level following the level parameter
 * 
 */
class LevelLoader
{
public:
    /**
     * @brief Deleted constructor and destructor
     *
     */
    LevelLoader() = delete;
    ~LevelLoader() = delete;

    /**
     * @brief Reads the level text file, and initializes the data of a level
     * 
     * @param level 
     * @return LevelData 
     */
    static LevelData load_level(int level);

private:
    /**
     * @brief Checks if the tag in the text files is correct. Adds a 
     * security layer
     *
     * @param level_tag
     * @return true
     * @return false
     */
    static bool check_tag(const std::string &level_tag);

    /**
     * @brief
     *
     * @param file
     * @return std::vector<Brick>
     */
    static std::vector<std::vector<std::shared_ptr<Brick>>> load_bricks(std::ifstream &file, LevelData &level_data);

    /**
     * @brief Converts a char into a Color
     *
     * @param c
     * @return Color
     */
    static Color color_from_char(const char &c);

    /**
     * @brief Converts a string into a Color
     *
     * @param str
     * @return Color
     */
    static Color color_from_string(const std::string &str);

    /**
     * @brief Converts a char into a Power
     *
     * @param c
     * @return Power
     */
    static Power power_up_from_char(const char &c);
};

#endif