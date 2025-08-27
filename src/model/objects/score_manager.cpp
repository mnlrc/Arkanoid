/**
 * @file score_manager.cpp
 * @author Manuel Rocca
 * @brief Source file for the ScoreManager class
 * @date 2025
 *
 */

#include "score_manager.hpp"

void ScoreManager::update_score(unsigned new_score)
{
    unsigned previous_score = 0;
    std::ifstream file;
    file.open(SCORE_PATH);

    std::string line;
    if (file.is_open())
    {
        getline(file, line);
        try
        {
            previous_score = static_cast<unsigned>(std::stoul(line));
        }
        catch (const std::exception &e)
        {
            Logger::log("[ERROR] Incorrect values in high_score.txt: " + std::string(e.what()));
        }
        file.close();
    }
    if (check_score(previous_score, new_score))
    {
        update_file_content(new_score);
    }
}

void ScoreManager::reset_score()
{
    std::ofstream ofs;
    ofs.open(SCORE_PATH, std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}

constexpr bool ScoreManager::check_score(unsigned previous_score, unsigned new_score)
{
    return new_score > previous_score;
}

void ScoreManager::update_file_content(unsigned new_high_score)
{
    std::ofstream write_file;
    write_file.open(SCORE_PATH);

    if (write_file.is_open())
    {
        std::string new_score = std::to_string(new_high_score);
        write_file << new_score;
        write_file.close();
    }
    else
    {
        Logger::log("[ERROR] Couldn't reopen file to update score");
    }
}