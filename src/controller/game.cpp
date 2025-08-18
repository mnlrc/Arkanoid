/**
 * @file game.cpp
 * @author Manuel Rocca
 * @brief Source file for the Game class
 * @date 2024
 *
 */

#include "game.hpp"

Game::Game()
{
    init_test(al_init(), "allegro init");
    controller_ = std::make_unique<Controller>();
    setupModel(ModelType::MAIN_MENU_MODEL);
    Logger::log("[INFO] Setting up Allegro and View");
    controller_->initView();
    setupAllegro();
    Logger::log("[INFO] Allegro successfully set up");
}

Game::~Game()
{
    al_destroy_event_queue(queue_);
    al_destroy_timer(timer_);
    al_uninstall_keyboard();
    al_uninstall_mouse();
}

void Game::setupModel(ModelType model)
{
    switch (model)
    {
    case ModelType::MAIN_MENU_MODEL:
        Logger::log("[INFO] Loading Main Menu Model");
        controller_->setupMenuModel(WINDOW_WIDTH, WINDOW_HEIGHT);
        Logger::log("[INFO] Main Menu Model successfully loaded");
        break;
    case ModelType::GAME_MODEL:
        Logger::log("[INFO] Loading Game Model");
        controller_->setupGameModel();
        break;
    case ModelType::PAUSE_MENU_MODEL:
        Logger::log("[INFO] Loading Pause Menu Model");
        // TODO
        break;
    default:
        Logger::log("[ERROR] Unknown model type received when loading new one");
        break;
    }
}

void Game::setupAllegro()
{
    timer_ = al_create_timer(1.0 / FREQUENCY);
    queue_ = al_create_event_queue();

    // init tests
    init_test(timer_, "timer");
    init_test(queue_, "queue");
    init_test(al_install_keyboard(), "keyboard");
    init_test(al_install_mouse(), "mouse");

    // link events to queue
    al_register_event_source(queue_, al_get_display_event_source(controller_->getDisplay()));
    al_register_event_source(queue_, al_get_timer_event_source(timer_));
    al_register_event_source(queue_, al_get_keyboard_event_source());
    al_register_event_source(queue_, al_get_mouse_event_source());
}

void Game::run()
{
    while (main_loop)
    {
        Logger::log("[INFO] Entering main loop, loading Main Menu");
        runMainMenu();

        while (game_loop)
        {
            Logger::log("[INFO] Starting game, entering game loop");
            runGame();

            while (pause_loop)
            {
                Logger::log("[INFO] Opening pause menu, entering pause loop");
                runPauseMenu();
            }
        }
    }
}

void Game::runMainMenu()
{
    bool done = false;
    bool draw = false;
    al_flush_event_queue(queue_);
    al_start_timer(timer_);
    while (!done)
    {
        al_wait_for_event(queue_, nullptr);
        while (al_get_next_event(queue_, &event_))
        {
            Logger::log("[INFO] Handling event");
            switch (event_.type)
            {
            case ALLEGRO_EVENT_KEY_DOWN:
                Logger::log("[INFO] Event type: ALLEGRO_EVENT_KEY_DOWN");
                handle_input_response(controller_->handleKeyInput(event_.keyboard.keycode), done);
                break;
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                Logger::log("[INFO] Event type: ALLEGRO_EVENT_DISPLAY_CLOSE");
                done = true;
                main_loop = false;
                break;
            case ALLEGRO_EVENT_TIMER:
                Logger::log("[INFO] Event type: ALLEGRO_EVENT_TIMER");
                draw = true;
                al_stop_timer(timer_);
                break;
            default:
                Logger::log("[ERROR] Unhandled input");
                break;
            }
        }
        if (draw)
        {
            draw = false;
            al_start_timer(timer_);
            controller_->updateView();
        }
    }
}

void Game::runGame()
{
    bool done = false;
    bool draw = false;
    controller_->setupGameModel();
    al_flush_event_queue(queue_);
    al_start_timer(timer_);
    while (!done)
    {
        al_wait_for_event(queue_, nullptr);
        while (al_get_next_event(queue_, &event_))
        {
            Logger::log("[INFO] Handling in game event");
            switch (event_.type)
            {
            case ALLEGRO_EVENT_KEY_DOWN:
                handle_input_response(controller_->handleKeyInput(event_.keyboard.keycode), done);
                break;
            case ALLEGRO_EVENT_TIMER:
                draw = true;
                al_stop_timer(timer_);
                break;
            default:
                Logger::log("[ERROR] Unhandled input");
            }
        }
        if (draw)
        {
            draw = false;
            al_start_timer(timer_);
            controller_->updateView();
        }
    }
}

void Game::runPauseMenu() {}

void Game::handle_input_response(Input_response response, bool &done)
{
    if (main_loop)
    {
        if (game_loop)
        {
            switch (response)
            {
            case Input_response::QUIT:
                done = true;
                game_loop = false;
                break;
            default:
                break;
            }
        }
        else
        {
            switch (response)
            {
            case Input_response::QUIT:
                done = true;
                main_loop = false;
                break;
            case Input_response::ENTER:
                done = true;
                game_loop = true;
            default:
                break;
            }
        }
    }
}
