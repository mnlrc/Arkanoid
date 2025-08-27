/**
 * @file text.hpp
 * @author Manuel Rocca
 * @brief Header file for the Text class
 * @date 2025
 *
 */

#ifndef TEXT_HPP
#define TEXT_HPP

// #### Internal inclusions ####
#include "point.hpp"
#include "../../global_variables.hpp"

// #### C++ inclusions ####
#include <string>

class Text
{
public:
    /**
     * @brief Construct a new Text object
     *
     * @param str
     * @param color
     */
    Text(std::string str, Color color);

    /**
     * @brief Destroy the Text object
     *
     */
    ~Text() = default;

    /**
     * @brief Get the text
     *
     * @return std::string
     */
    std::string get_text() const noexcept;

    /**
     * @brief Get the color of the text
     *
     * @return Color
     */
    Color get_color() const noexcept;

private:
    std::string text_;
    Color color_;
};

#endif