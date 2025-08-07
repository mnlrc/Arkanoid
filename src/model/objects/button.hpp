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
    /**
     * @brief Construct a new Button object
     *
     * @param texts
     * @param center
     * @param width
     * @param height
     */
    Button(const std::vector<Text> &texts, const Point &center, double width, double height);

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
    Rectangle rect_;
};

#endif