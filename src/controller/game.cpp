/**
 * @file game.cpp
 * @author Manuel Rocca
 * @brief Source file for the Game class
 * @date 2024
 *
 */

#include "game.hpp"

void Game::setupGame(){
    al_register_event_source(queue_, al_get_display_event_source(gameView_.getDisplay()));
    al_register_event_source(queue_, al_get_timer_event_source(timer_));
    al_register_event_source(queue_, al_get_keyboard_event_source());
    
    al_start_timer(timer_);
}


void Game::manageKeyDown(ALLEGRO_EVENT event){
    switch (event.keyboard.keycode) {
        case 59: // escape
            std::cout << "Program ended." << std::endl;
            done = true;
            break;
        case KEY_LEFT: // Q
            inputKeys_["left"] = true;
            break;
        case KEY_RIGHT: // D
            inputKeys_["right"] = true;
            break;
        case KEY_SPACE:
            yes = true;
            break;
        default: {}
    } 
}

void Game::manageKeyUp(ALLEGRO_EVENT event) {
    switch (event.keyboard.keycode) {
        case KEY_LEFT: // Q
            inputKeys_["left"] = false;
            break;
        case KEY_RIGHT: // D
            inputKeys_["right"] = false;
            break;
        default: {}
    }
}

void Game::update() {
    // gérer le déplacement de la balle + collisions etc
    if (inputKeys_["right"]) {
        control_.move(racket_, inputKeys_["right"]);
    }
    else if (inputKeys_["left"]) {
        control_.move(racket_, !inputKeys_["left"]);
    }
    if (yes) control_.move(balls_, racket_);
    gameView_.drawAll(racket_, balls_, bricks_);
}


void Game::runGame(){
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


Game::Game(View gameview): gameView_(gameview), racket_(Point{WINDOW_WIDTH / 2, WINDOW_HEIGHT - 50}, WINDOW_WIDTH / 5, WINDOW_HEIGHT / 25) {
    
    // Init bricks -> TODO/TOCOMPLETE
    float brickWidth = (WINDOW_WIDTH - 10) / BRICKS_COLS;
    float brickHeight = (WINDOW_HEIGHT / 3) / BRICKS_ROWS;
    float yPos = 0.25 *  WINDOW_HEIGHT; float xPos = 5;
    bricks_.resize(BRICKS_ROWS);

    for (size_t i = 0; i < BRICKS_ROWS; i++) {
        for (size_t j = 0; j < BRICKS_COLS; j++) {
            bricks_[i].push_back(Brick(brickWidth, brickHeight, Point{xPos, yPos}));
            xPos += brickWidth;
        }
        yPos += brickHeight;
        xPos = 5;
    }
    // Init balls
    balls_.push_back(Ball(Point{WINDOW_WIDTH / 2, WINDOW_HEIGHT - 75}, 10, DEFAULT_BALL_SPEED, -DEFAULT_BALL_SPEED));
    
    timer_ = al_create_timer(1.0/FREQUENCY);
    queue_ = al_create_event_queue();
    
    // Tests if everything is correctly initialized
    init_test(timer_, "timer");
    init_test(queue_, "queue");
    init_test(al_init_primitives_addon(), "primitives");
    init_test(al_install_keyboard(), "keyboard");

    setupGame();
}


Game::~Game() {
    al_destroy_event_queue(queue_);
    al_destroy_display(gameView_.getDisplay()); // ou appeler le destructeur de View??
    al_destroy_timer(timer_);
}