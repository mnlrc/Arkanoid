/**
 * @file game.cpp
 * @author Manuel Rocca
 * @brief Source file for the Game class
 * @date 2024
 *
 */

#include "game.hpp"

Game::Game() {
    
    // Init bricks -> TODO/TOCOMPLETE
    double brick_height = (WINDOW_HEIGHT / 3) / static_cast<double>(BRICKS_ROWS);
    double brick_width = WINDOW_WIDTH / static_cast<double>(BRICKS_COLS);

    double y = brick_height / 2;
    for (size_t i = 0; i < BRICKS_ROWS; i++) {
        double x = brick_width / 2;
        std::vector<Brick> v;
        for (size_t j = 0; j < BRICKS_COLS; j++) {
            v.push_back(Brick(Point{x, y}, brick_width, brick_height, true));
            x += brick_width;
        }
        y += brick_height;
        bricks_.push_back(v);
    }

    // Init balls
    balls_.push_back(Ball(Point{WINDOW_WIDTH / 2, WINDOW_HEIGHT - 75}, 10, Point{DEFAULT_BALL_SPEED, -DEFAULT_BALL_SPEED}));
    
    timer_ = al_create_timer(1.0/FREQUENCY);
    queue_ = al_create_event_queue();
    
    // Tests if everything is correctly initialized
    init_test(timer_, "timer");
    init_test(queue_, "queue");
    init_test(al_install_keyboard(), "keyboard");
    // init_test(al_install_mouse, "mouse");

    setupGame();
}


Game::~Game() {
    al_destroy_event_queue(queue_);
    al_destroy_timer(timer_);
    al_uninstall_keyboard();
    al_uninstall_mouse();
}

void Game::setupGame() {
    al_register_event_source(queue_, al_get_display_event_source(gameView_.getDisplay()));
    al_register_event_source(queue_, al_get_timer_event_source(timer_));
    al_register_event_source(queue_, al_get_keyboard_event_source());
    
    al_start_timer(timer_);
}


void Game::manageKeyDown(ALLEGRO_EVENT event) {
    int keycode = event.keyboard.keycode;
    if (keycode == ALLEGRO_KEY_Q or keycode == ALLEGRO_KEY_A) { inputKeys_["left"] = true; }
    else if (keycode == ALLEGRO_KEY_D or keycode == ALLEGRO_KEY_P) { inputKeys_["right"] = true; }
    else if (keycode == ALLEGRO_KEY_SPACE) { yes = true; }
    else if (keycode == ALLEGRO_KEY_ESCAPE) { 
        std::cout << "Program ended." << std::endl;
        done = true; 
        }
}

void Game::manageKeyUp(ALLEGRO_EVENT event) {
    int keycode = event.keyboard.keycode;
    if (keycode == ALLEGRO_KEY_Q or keycode == ALLEGRO_KEY_A) { inputKeys_["left"] = false; }
    else if (keycode == ALLEGRO_KEY_D or keycode == ALLEGRO_KEY_P) { inputKeys_["right"] = false; }
}

void Game::update() {
    // gérer le déplacement de la balle + collisions etc
    // moving racket
    if (inputKeys_["right"]) {
        control_.move(racket_, inputKeys_["right"]);
    }
    else if (inputKeys_["left"]) {
        control_.move(racket_, !inputKeys_["left"]);
    }

    // moving ball
    if (yes) { // TODO => if (yes) : if balls.isMoving()
        control_.move(balls_, racket_, bricks_);
    } 
    else {
        control_.move(balls_, racket_);
    }
    
    gameView_.drawAll(racket_, balls_, bricks_);
}


void Game::runGame() {
    while (!done) {
        al_wait_for_event(queue_, &event_);
        switch (event_.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;
            case ALLEGRO_EVENT_TIMER:
                update();// TODO
                break;
            case ALLEGRO_EVENT_KEY_DOWN: // TODO
                manageKeyDown(event_);
                break;
            case ALLEGRO_EVENT_KEY_UP:
                manageKeyUp(event_);
                break;
            default: {
            }
        }
  }
}
