/**
 * @file text.hpp
 * @author Manuel Rocca
 * @brief Header file for the Text class
 * @date 2025
 *
 */

#ifndef TEXT_HPP
#define TEXT_HPP

#include <string>

#include "point.hpp"
#include "../../global_variables.hpp"

class Text
{
public:

    Text(std::string str, Color color);

    /**
     * @brief Destroy the Text object
     *
     */
    ~Text() = default;

    /**
     * @brief Get the Text object
     *
     * @return std::string
     */
    std::string get_text() const noexcept;

    /**
     * @brief Get the Color object
     *
     * @return Color
     */
    Color get_color() const noexcept;

private:
    std::string text_;
    Color color_;
};

#endif