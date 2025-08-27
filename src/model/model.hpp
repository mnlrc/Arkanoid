/**
 * @file model.hpp
 * @author Manuel Rocca
 * @brief Header file for the Model class
 * @date 2025
 *
 */

#ifndef MODEL_HPP
#define MODEL_HPP

#include "../global_variables.hpp"

class Model
{
public:
    /**
     * @brief Construct a new Model object
     *
     * @param width The width of the model's window
     * @param height The height of the model's window
     */
    Model(const int width, const int height);

    /**
     * @brief Destroy the Model object
     * It is virtual because of it's inheritance
     *
     */
    virtual ~Model() = default;

    /**
     * @brief Get the width_ attribute
     *
     * @return The width of the Model
     */
    int get_width() const noexcept;

    /**
     * @brief Get the height_ attribute
     *
     * @return The height of the Model
     */
    int get_height() const noexcept;

    /**
     * @brief Get the inner_color_ attribute
     *
     * @return The Color inner_color_ attribute of the Model
     */
    Color get_inner_color() const noexcept;

    /**
     * @brief Get the outer_color_ attribute
     *
     * @return The Color outer_color_ attribute of the Model
     */
    Color get_outer_color() const noexcept;

protected:
    const int width_;
    const int height_;
    Color inner_color_ = Color::GREY;
    Color outer_color_ = Color::BLACK;
};

#endif