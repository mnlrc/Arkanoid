/**
 * @file game.cpp
 * @author Manuel Rocca
 * @brief Source file for the Game class
 * @date 2025
 *
 */

#include "game.hpp"

Game::Game()
{
    init_test(al_init(), "allegro init");
    std::shared_ptr view = std::make_shared<View>(WINDOW_WIDTH, WINDOW_HEIGHT);
    game_controller_ = std::make_unique<GameController>(view);
    menu_controller_ = std::make_unique<MenuController>(view);

    Logger::log("[INFO] Setting up Allegro");
    setup_allegro(view);
    Logger::log("[INFO] Allegro successfully set up");
}

Game::~Game()
{
    al_destroy_event_queue(queue_);
    al_destroy_timer(timer_);
    al_uninstall_keyboard();
    al_uninstall_mouse();
}

void Game::setup_allegro(std::shared_ptr<View> view)
{
    timer_ = al_create_timer(1.0 / FREQUENCY);
    queue_ = al_create_event_queue();

    // init tests
    init_test(timer_, "timer");
    init_test(queue_, "queue");
    init_test(al_install_keyboard(), "keyboard");
    init_test(al_install_mouse(), "mouse");

    // link events to queue
    al_register_event_source(queue_, al_get_display_event_source(view->get_display()));
    al_register_event_source(queue_, al_get_timer_event_source(timer_));
    al_register_event_source(queue_, al_get_keyboard_event_source());
    al_register_event_source(queue_, al_get_mouse_event_source());
}

void Game::run()
{
    while (main_loop)
    {
        Logger::log("[INFO] Entering main loop, loading Main Menu");
        run_main_menu();

        while (game_loop)
        {
            Logger::log("[INFO] Starting game, entering game loop");
            short int selected_level = menu_controller_->get_selected_level();
            run_game(selected_level);
        }
    }
}

void Game::run_main_menu()
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
            switch (event_.type)
            {
            case ALLEGRO_EVENT_KEY_DOWN:
                Logger::log("[INFO] Event type: ALLEGRO_EVENT_KEY_DOWN");
                handle_input_response(menu_controller_->handle_key_down(event_.keyboard.keycode), done);
                break;
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                Logger::log("[INFO] Event type: ALLEGRO_EVENT_DISPLAY_CLOSE");
                done = true;
                main_loop = false;
                break;
            case ALLEGRO_EVENT_TIMER:
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
            menu_controller_->update_view();
        }
    }
}

void Game::run_game(short level)
{
    bool done = false;
    bool draw = false;
    if (!game_controller_->setup_game_model(level))
    {
        game_loop = false;
        Logger::log("[ERROR] Level couldn't be initialized, leaving game loop");
        return;
    }
    al_flush_event_queue(queue_);
    al_start_timer(timer_);
    while (!done)
    {
        al_wait_for_event(queue_, nullptr);
        while (al_get_next_event(queue_, &event_))
        {
            switch (event_.type)
            {
            case ALLEGRO_EVENT_KEY_DOWN:
                handle_input_response(game_controller_->handle_key_down(event_.keyboard.keycode), done);
                break;
            case ALLEGRO_EVENT_KEY_UP:
                game_controller_->handle_key_up(event_.keyboard.keycode);
                break;
            case ALLEGRO_EVENT_MOUSE_AXES:
                game_controller_->handle_mouse_movement(event_);
                break;
            case ALLEGRO_EVENT_TIMER:
            {
                if (handle_update_response(game_controller_->update_model()))
                {
                    draw = false;
                }
                else
                {
                    draw = true;
                }
                al_stop_timer(timer_);
                break;
            }

            default:
                Logger::log("[ERROR] Unhandled input");
            }
        }
        if (draw)
        {
            draw = false;
            al_start_timer(timer_);
            game_controller_->update_view();
        }
    }
}

void Game::handle_input_response(InputResponse response, bool &done)
{
    if (main_loop)
    {
        if (game_loop)
        {
            switch (response)
            {
            case InputResponse::QUIT:
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
            case InputResponse::QUIT:
                done = true;
                main_loop = false;
                break;
            case InputResponse::ENTER:
                done = true;
                game_loop = true;
            default:
                break;
            }
        }
    }
}

bool Game::handle_update_response(UpdateResponse response)
{
    switch (response)
    {
    case UpdateResponse::CONTINUE:
    case UpdateResponse::NONE:
        return false; // no update needed, continue the game loop
    case UpdateResponse::GAME_OVER:
        game_controller_->draw_end(false);
        game_controller_->reset_game_model();
        return true;
    case UpdateResponse::GAME_WON:
        game_controller_->draw_end(true);
        game_controller_->reset_game_model();
        return true;
    default:
        Logger::log("[ERROR] Unhandled update response");
        return false; // default case, continue the game loop
    }
}