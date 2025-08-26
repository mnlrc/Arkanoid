/**
 * @file model.cpp
 * @author Manuel Rocca
 * @brief Source file for the Model class
 * @date 2025
 *
 */

#include "model.hpp"

Model::Model(const int width, const int height) : width_(width), height_(height) {}

const int Model::get_width() const noexcept { return width_; }

const int Model::get_height() const noexcept { return height_; }

const Color Model::get_inner_color() const noexcept { return inner_color_; }

const Color Model::get_outer_color() const noexcept { return outer_color_; }