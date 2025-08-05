/**
 * @file model.hpp
 * @author Manuel Rocca
 * @brief Header file for the Model class
 * @date 2025
 *
 */

#ifndef MODEL_HPP
#define MODEL_HPP

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
     *
     */
    ~Model() = default;

    /**
     * @brief Get the width_ attribute
     *
     * @return const int
     */
    const int getWidth() const noexcept;

    /**
     * @brief Get the height_ attribute
     *
     * @return const int
     */
    const int getHeight() const noexcept;

protected:
    const int width_;
    const int height_;
};

#endif