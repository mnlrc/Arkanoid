/**
 * @file menu_model.cpp
 * @author Manuel Rocca
 * @brief Source file for the MenuModel class
 * @date 2025
 *
 */

#ifndef MENU_MODEL_HPP
#define MENU_MODEL_HPP

#define NUMBER_OF_BUTTONS 3

#include <cmath>
#include <string>
#include <unordered_map>
#include <map>

#include "../model.hpp"
#include "../objects/rectangle.hpp"
#include "../objects/button.hpp"
#include "../objects/text.hpp"
#include "../../global_variables.hpp"
#include "../../log/logger.hpp"

const std::string PLAY_BUTTON_TEXT = "Play - Enter";
const std::string EXIT_BUTTON_TEXT = "Quit Game - Escape";
const std::string LEVEL_1 = "<-      Level 1      ->";
const std::string LEVEL_2 = "<-      Level 2      ->";
const std::string LEVEL_3 = "<-      Level 3      ->";
const std::string LEVEL_4 = "<-      Level 4      ->";
const std::string LEVEL_5 = "<-      Level 5      ->";
const std::vector<std::string> LEVEL_BUTTON_TEXT = {LEVEL_1,
                                                    LEVEL_2,
                                                    LEVEL_3,
                                                    LEVEL_4,
                                                    LEVEL_5};

class MenuModel final : public Model
{
public:
    /**
     * @brief Construct a new Menu Model object
     *
     * @param width The width of the model's window
     * @param height The height of the model's window
     */
    MenuModel(const int width, const int height);

    /**
     * @brief Get the Buttons object
     *
     * @return Rectangle*
     */
    std::vector<Button> get_buttons();

    /**
     * @brief
     *
     * @param direction
     */
    void cycle_text(Direction direction);

    /**
     * @brief Get the selected level object
     *
     * @return int
     */
    int get_selected_level();

private:
    std::vector<Button> buttons_;
};

#endif