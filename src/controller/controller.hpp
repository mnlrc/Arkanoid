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
#include "../view/view.hpp"

enum class Input_response : int
{
    QUIT = 0,
    ENTER,
    NONE,
};

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
     */
    void initView();

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

    /**
     * @brief
     *
     * @param keyCode
     */
    Input_response handleKeyInput(int keyCode);

    /**
     * @brief
     *
     */
    void updateView();

    /**
     * @brief Get the View object
     *
     * @return View
     */
    ALLEGRO_DISPLAY *getDisplay() const noexcept;

    /**
     * @brief
     *
     */
    void swap_model();

private:
    std::unique_ptr<View> view_;

    std::unique_ptr<MenuModel> menu_model;
    std::unique_ptr<GameModel> game_model;
    // std::unique_ptr<PauseModel> pause_model;

    ModelType current_model;

    Input_response handle_menu_input(int key_code);

    Input_response handle_game_input(int key_code);
};