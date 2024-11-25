#include "game.hpp"

void Game::setupGame(){
    al_register_event_source(queue_, al_get_display_event_source(gameView_.getDisplay()));
    al_register_event_source(queue_, al_get_timer_event_source(timer_));
    al_register_event_source(queue_, al_get_keyboard_event_source());
    
    al_start_timer(timer_);
}


void Game::cleanUpGame(){
    al_destroy_event_queue(queue_);
    al_destroy_display(gameView_.getDisplay());
    al_destroy_timer(timer_);
}


void Game::manageKey(ALLEGRO_EVENT event){
    switch (event.keyboard.keycode) {
        case 59: // escape
            std::cout << "Program ended." << std::endl;
            done = true;
            break;
        case 17: // Q
            // racket_.move(-15);
            break;
        case 4: // D
            // racket_.move(15);
            break;
        default: {}
    } 
}

void Game::update() {
    // gérer le déplacement de la balle + collisions etc
    gameView_.draw(racket_, balls_, bricks_);
}


void Game::runGame(){
    setupGame();
    while (!done) {
    al_wait_for_event(queue_, &event_);
    switch (event_.type) {
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            done = true;
            break;
        case ALLEGRO_EVENT_TIMER:
            update();// TODO
            break;
        case ALLEGRO_EVENT_KEY_CHAR: // TODO
            manageKey(event_);
        default: {
      }
    }
  }
    cleanUpGame();
}


Game::Game(): gameView_(), racket_(Point{WINDOW_WIDTH / 2, WINDOW_HEIGHT - 50}, WINDOW_WIDTH / 5, WINDOW_HEIGHT / 25) {
    
    // Init bricks
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
    balls_.push_back(Ball(Point{WINDOW_WIDTH / 2, WINDOW_HEIGHT - 80}, 12));
    
    init_test(al_init(), "allegro");
    timer_ = al_create_timer(1.0/FREQUENCY);
    queue_ = al_create_event_queue();
    
    // Tests if everything is correctly initialized
    init_test(timer_, "timer");
    init_test(queue_, "queue");
    init_test(al_init_primitives_addon(), "primitives");
    init_test(al_install_keyboard(), "keyboard");
}


Game::~Game() {}