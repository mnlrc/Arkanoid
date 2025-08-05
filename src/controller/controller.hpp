/**
 * @file controller.hpp
 * @author Manuel Rocca
 * @brief Header file for the Controller class.
 * @date 2025
 */

#include <memory>

#include "../model/main_menu/menu_model.hpp"
#include "../model/game/game_model.hpp"
#include "../model/pause_menu/pause_model.hpp"

class Controller
{
public:
    /**
     * @brief Construct a new Controller object
     *
     */
    Controller() = default;

    /**
     * @brief Destroy the Controller object
     *
     */
    ~Controller() = default;

    /**
     * @brief
     *
     * @param width
     * @param height
     */
    void setupMenuModel(const int width, const int height);

    /**
     * @brief 
     * 
     */
    void setupGameModel();

    /**
     * @brief 
     * 
     */
    void setupPauseModel();

    void handleKeyInput(int keyCode);

    void updateView();

private:
    std::unique_ptr<MenuModel> menu_model;
    // std::unique_ptr<GameModel> game_model;
    // std::unique_ptr<PauseModel> pause_model;

    ModelType current_model;
};