/**
 * @file button.hpp
 * @author Manuel Rocca
 * @brief Header file for the Button class
 * @date 2025
 *
 */

#ifndef BUTTON_HPP
#define BUTTON_HPP

// #### Internal inclusions ####
#include "rectangle.hpp"
#include "text.hpp"
#include "../../log/logger.hpp"

// #### C++ inclusions ####
#include <vector>
#include <string>

class Button
{
public:
    /**
     * @brief Construct a new Button object
     *
     * @param texts The texts held by the button, that it can display
     * @param center
     * @param width
     * @param height
     * @param inner_color
     * @param outer_color
     */
    Button(const std::vector<Text> &texts, Point center, double width, double height, Color inner_color, Color outer_color);

    /**
     * @brief Destroy the Button object
     *
     */
    ~Button() = default;

    /**
     * @brief Get the currently selected text
     *
     * @return const Text&
     */
    const Text &get_selected_text() const noexcept;

    /**
     * @brief Cycle through the texts
     * in the right direction
     *
     */
    void next_text();

    /**
     * @brief Cycle through the texts
     * in the left direction
     *
     */
    void previous_text();

    /**
     * @brief Select a specific text
     * 
     * @param idx 
     */
    void set_selected_text(size_t idx);

    /**
     * @brief Get the rectangle_ attribute
     *
     * @return const Rectangle&
     */
    const Rectangle &get_rectangle() const noexcept;

private:
    std::vector<Text> texts_;
    size_t idx_;
    Rectangle rectangle_;
};

#endif