/**
 * @file menu_controller.hpp
 * @author Manuel Rocca
 * @brief Header file for the MenuController class.
 * @date 2025
 */

#ifndef MENU_CONTROLLER_HPP
#define MENU_CONTROLLER_HPP

#include "controller.hpp"

#include <memory>

class MenuController : public Controller
{
public:
    MenuController(std::shared_ptr<View> view);

    ~MenuController() = default;

    InputResponse handle_key_down(int key_code) override;

    void update_view() override;

    short int get_selected_level() const noexcept;

private:
    std::unique_ptr<MenuModel> menu_model_;
};

#endif