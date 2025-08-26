/**
 * @file allegro_test.cpp
 * @author Manuel Rocca
 * @brief Source file for the test functions
 * @date 2025
 *
 */

#include "allegro_test.hpp"

void init_test(bool test, const char *description)
{
    if (!test)
    {
        Logger::log("[ERROR] Couldn't initialize " + std::string(description));
    }
}

void init_test(void *test, const char *description)
{
    init_test(test != nullptr, description);
}