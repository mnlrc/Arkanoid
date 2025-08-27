/**
 * @file controller.hpp
 * @author Manuel Rocca
 * @brief Header file for the Controller class.
 * @date 2025
 */

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

// #### Internal inclusions ####
#include "../model/main_menu/menu_model.hpp"
#include "../view/view.hpp"
#include "../model/game/game_model.hpp"

// #### C++ inclusions ####
#include <memory>

/**
 * @brief Parent class for the controllers, regroups common
 * logic by holding mostly virtual methods
 *
 */
class Controller
{
public:
    /**
     * @brief Construct a new Controller object
     *
     * @param view: The view that the controller controls
     */
    Controller(std::shared_ptr<View> view);

    /**
     * @brief Virtual destructor of the Controller class
     *
     */
    virtual ~Controller() = default;

    virtual InputResponse handle_key_down(int key_code) = 0;
    virtual void handle_key_up([[maybe_unused]] int key_code) {}
    virtual void update_view() = 0;

    /**
     * @brief Get the view_ attribute
     *
     * @return ALLEGRO_DISPLAY*
     */
    ALLEGRO_DISPLAY *get_display() const noexcept;

protected:
    std::shared_ptr<View> view_;
};

#endif