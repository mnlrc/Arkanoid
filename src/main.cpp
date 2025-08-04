/**
 * @file main.cpp
 * @author Manuel Rocca
 * @brief Source file for the main function
 * @date 2025
 *
 */

#include "controller/game.hpp"
#include "log/logger.hpp"


int main()
{
    Logger::log("Start of the program");

    Game game = Game();
    game.runGame();

    Logger::log("Program ended, returning 0");
    return 0;
}