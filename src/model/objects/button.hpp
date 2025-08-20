/**
 * @file button.hpp
 * @author Manuel Rocca
 * @brief Header file for the Button class
 * @date 2025
 *
 */

#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <vector>
#include <string>

#include "rectangle.hpp"
#include "text.hpp"

/**
 * @brief
 *
 */
class Button
{
public:
    Button(const std::vector<Text> &texts, Point &center, double width, double height, Color inner_color, Color outer_color);

    /**
     * @brief Destroy the Button object
     *
     */
    ~Button() = default;

    /**
     * @brief Get the Selected Text object
     *
     * @return const Text&
     */
    const Text &getSelectedText() const noexcept;

    /**
     * @brief
     *
     */
    void nextText();

    /**
     * @brief
     *
     */
    void previousText();

    /**
     * @brief Get the Rectangle object
     *
     * @return const Rectangle&
     */
    const Rectangle &getRectangle() const noexcept;

private:
    std::vector<Text> texts_;
    size_t idx_;
    Rectangle rectangle_;
};

#endif