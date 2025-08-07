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
    /**
     * @brief Construct a new Text object
     *
     * @param t The text
     * @param c The color of the text
     * @param p The position of the center of the text on the model
     */
    Text(std::string t, Color c, Point p);

    /**
     * @brief Construct a new Text object
     *
     */
    Text() = default;

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
    std::string getText() const noexcept;

    /**
     * @brief Get the Color object
     *
     * @return Color
     */
    Color getColor() const noexcept;

    /**
     * @brief Get the Center object
     *
     * @return Point
     */
    Point getCenter() const noexcept;

private:
    std::string text_;
    Color color_;
    Point center_;
};

#endif