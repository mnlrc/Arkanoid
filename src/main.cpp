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
    Logger::get_instance(); // init the logger
    Logger::log("[INFO] Start of the program");

    Game game = Game();
    game.run();

    Logger::log("[INFO] Program ended, returning 0");
    return 0;
}