/**
 * @file model.cpp
 * @author Manuel Rocca
 * @brief Source file for the Model class
 * @date 2025
 *
 */

#include "model.hpp"

Model::Model(const int width, const int height) : width_(width), height_(height) {}

int Model::get_width() const noexcept { return width_; }

int Model::get_height() const noexcept { return height_; }

Color Model::get_inner_color() const noexcept { return inner_color_; }

Color Model::get_outer_color() const noexcept { return outer_color_; }

void Model::set_inner_color(Color new_color) noexcept { inner_color_ = new_color; }

void Model::set_outer_color(Color new_color) noexcept { outer_color_ = new_color; }
