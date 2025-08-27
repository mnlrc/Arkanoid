/**
 * @file menu_controller.cpp
 * @author Manuel Rocca
 * @brief Source file for the MenuController class.
 * @date 2025
 */

#include "menu_controller.hpp"

MenuController::MenuController(std::shared_ptr<View> view) : Controller{view}
{
    menu_model_ = std::make_unique<MenuModel>(WINDOW_WIDTH, WINDOW_HEIGHT);
}

InputResponse MenuController::handle_key_down(int key_code)
{
    switch (key_code)
    {
    case ALLEGRO_KEY_ESCAPE:
        return InputResponse::QUIT;
    case ALLEGRO_KEY_ENTER:
        return InputResponse::ENTER;
    case ALLEGRO_KEY_LEFT:
        menu_model_->cycle_text(Direction::LEFT);
        return InputResponse::NONE;
    case ALLEGRO_KEY_RIGHT:
        menu_model_->cycle_text(Direction::RIGHT);
        return InputResponse::NONE;
    case ALLEGRO_KEY_R:
        ScoreManager::reset_score();
    default:
        Logger::log("[ERROR] Invalid input");
        return InputResponse::NONE;
    }
}

void MenuController::update_view() { view_->render_menu_model(menu_model_); }

short int MenuController::get_selected_level() const noexcept { return menu_model_->get_selected_level(); }