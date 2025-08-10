/**
 * @file model.cpp
 * @author Manuel Rocca
 * @brief Source file for the Model class
 * @date 2025
 *
 */

#include "model.hpp"

Model::Model(const int width, const int height) : width_(width), height_(height) {}

const int Model::getWidth() const noexcept { return width_; }

const int Model::getHeight() const noexcept { return height_; }

const Color Model::getInnerColor() const noexcept { return inner_color_; }

const Color Model::getOuterColor() const noexcept { return outer_color_; }