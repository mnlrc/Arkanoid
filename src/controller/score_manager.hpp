/**
 * @file score_manager.hpp
 * @author Manuel Rocca
 * @brief Header file for the ScoreManager class
 * @date 2025
 *
 */

#ifndef SCORE_MANAGER_HPP
#define SCORE_MANAGER_HPP

// #### Internal inclusions ####
#include "../log/logger.hpp"

// #### C++ inclusions ####
#include <string>
#include <fstream>

constexpr std::string SCORE_PATH = "high_score.txt";

/**
 * @brief A static class used to update the high_score in a dedicated
 * text file
 *
 */
class ScoreManager
{
public:
    /**
     * @brief Deleted constructor and destructor
     *
     */
    ScoreManager() = delete;
    ~ScoreManager() = delete;

    /**
     * @brief Updates the score in the text file if the
     * new score is higher than the previous one
     *
     * @param new_score
     */
    static void update_score(unsigned new_score);

    /**
     * @brief Reset the score by clearing the text file's contents
     *
     */
    static void reset_score();

private:
    /**
     * @brief Checks if the new score is higher than the previous one
     *
     * @param previous_score
     * @param new_score
     * @return true: the new score is higher
     * @return false: the new score is lower
     */
    static constexpr bool check_score(unsigned previous_score, unsigned new_score);

    /**
     * @brief Writes the new high score in the text file
     *
     * @param new_high_score
     */
    static void update_file_content(unsigned new_high_score);
};

#endif