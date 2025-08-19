/**
 * @file controller.hpp
 * @author Manuel Rocca
 * @brief Header file for the Controller class.
 * @date 2025
 */

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <memory>

#include "../model/main_menu/menu_model.hpp"
#include "../view/view.hpp"
#include "../model/game/game_model.hpp"
#include "../model/game/engine.hpp"

enum class InputResponse : int
{
    QUIT = 0,
    ENTER,
    NONE,
};

class Controller
{
public:
    Controller(std::shared_ptr<View> view);
    ~Controller() = default;

    virtual InputResponse handle_key_down(int key_code) = 0;
    virtual void handle_key_up([[maybe_unused]] int key_code) {}
    virtual void update_view() = 0;
    virtual void update_model() {}

    ALLEGRO_DISPLAY *get_display() const noexcept;

protected:
    std::shared_ptr<View> view_;
};

#endif