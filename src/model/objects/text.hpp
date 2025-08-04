/**
 * @file text.hpp
 * @author Manuel Rocca
 * @brief Header file for the Text class
 * @date 2025
 *
 */

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

private:
    std::string text_;
    Color color_;
    Point center_;
};