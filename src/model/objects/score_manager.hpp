/**
 * @file score_manager.hpp
 * @author Manuel Rocca
 * @brief Header file for the ScoreManager class
 * @date 2025
 *
 */

#ifndef SCORE_MANAGER_HPP
#define SCORE_MANAGER_HPP

#include <string>
#include <fstream>

#include "../../log/logger.hpp"

constexpr std::string SCORE_PATH = "high_score.txt";

class ScoreManager
{
public:
    ScoreManager() = delete;
    ~ScoreManager() = delete;

    /**
     * @brief
     *
     * @param new_score
     */
    static void update_score(unsigned new_score);

    static void reset_score();

private:
    static constexpr bool check_score(unsigned previous_score, unsigned new_score);

    static void update_file_content(unsigned new_high_score);
};

#endif