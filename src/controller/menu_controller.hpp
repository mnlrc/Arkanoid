/**
 * @file menu_controller.hpp
 * @author Manuel Rocca
 * @brief Header file for the MenuController class.
 * @date 2025
 */

#ifndef MENU_CONTROLLER_HPP
#define MENU_CONTROLLER_HPP

// #### Internal inclusions ####
#include "controller.hpp"
#include "score_manager.hpp"

// #### C++ inclusions ####
#include <memory>

/**
 * @brief GameController handles the Main Menu where the player can select the level
 * It handles the inputs, updates and sets up the Models, updates the view, ...
 *
 */
class MenuController final : public Controller
{
public:
    /**
     * @brief Construct a new Menu Controller object
     *
     * @param view: The view to update
     */
    MenuController(std::shared_ptr<View> view);

    /**
     * @brief Handles the ALLEGRO_KEY_DOWN event by calling the right functions
     * based on the key_code
     *
     * @param key_code: The key code of the event
     *
     * @return InputResponse: A response to the input that signals any internal change in the Model
     */
    InputResponse handle_key_down(int key_code) override;

    /**
     * @brief Updates the view by giving it the MenuModel
     *
     */
    void update_view() override;

    /**
     * @brief Returns the currently selected level
     * 
     * @return short int, the selected level
     */
    short int get_selected_level() const noexcept;

private:
    std::unique_ptr<MenuModel> menu_model_;
};

#endif