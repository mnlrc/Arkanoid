/**
 * @file controller.hpp
 * @author Manuel Rocca
 * @brief Header file for the Controller class.
 * @date 2025
 */

#include "controller.hpp"

Controller::Controller(std::shared_ptr<View> view) : view_(view) {}

ALLEGRO_DISPLAY *Controller::get_display() const noexcept { return view_->getDisplay(); }