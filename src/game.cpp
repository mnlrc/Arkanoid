#include "game.hpp"

void Game::setupGame(){
    al_register_event_source(queue, al_get_display_event_source(window.getDisplay()));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_keyboard_event_source());
    
    al_start_timer(timer);
}

void Game::cleanUpGame(){
    al_destroy_event_queue(queue);
    al_destroy_display(window.getDisplay());
    al_destroy_timer(timer);
}

void Game::draw(){
    al_clear_to_color(al_map_rgb(0, 0, 0));
    window.draw_game_limits();
    racket.draw();
    al_flip_display();
}

void Game::manageKey(ALLEGRO_EVENT event){
    switch (event.keyboard.keycode) {
        case 59: // escape
            std::cout << "Program ended." << std::endl;
            done = true;
            break;
        case 17: // Q
            racket.move(-15);
            break;
        case 4: // D
            racket.move(15);
            break;
        default: {}

    }
    
}

Game::Game(): window(), racket((WIDTH / 2), (WIDTH / 5)){
    //INITIALIZE ATTRIBUTES => racket, window, ball?, bricks, ...
    window.center_window();
    timer = al_create_timer(1.0/FREQUENCY);
    queue = al_create_event_queue();
    
    // Tests if everything is correctly initialized
    init_test(timer, "timer");
    init_test(queue, "queue");
    init_test(al_init_primitives_addon(), "primitives");
    init_test(al_install_keyboard(), "keyboard");
}

Game::~Game(){

}

void Game::runGame(){
    setupGame();
    while (!done) {
    al_wait_for_event(queue, &event);
    switch (event.type) {
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            done = true;
            break;
        case ALLEGRO_EVENT_TIMER:
            draw();
            break;
        case ALLEGRO_EVENT_KEY_DOWN:
            manageKey(event);
        default: {
      }
    }
  }
    cleanUpGame();
}