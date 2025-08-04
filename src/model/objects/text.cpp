/**
 * @file text.cpp
 * @author Manuel Rocca
 * @brief Source file for the Text class
 * @date 2025
 *
 */

#include "text.hpp"

Text::Text(std::string t, Color c, Point p) : text_(t), color_(c), center_(p) {}