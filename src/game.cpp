#include "game.hpp"
#include "allegro_test.hpp"

Game::Game(): window(){
    //INITIALIZE ATTRIBUTES => racket, window, ball?, bricks, ...
}

void Game::runGame(){
    
    ALLEGRO_TIMER* timer = al_create_timer(1.0);
    init_test(timer, "timer");

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    init_test(queue, "queue");
    al_register_event_source(queue, al_get_display_event_source(window.getDisplay()));
    
    bool quitter = false;
    while (!quitter) {
        ALLEGRO_EVENT event;
        al_wait_for_event(queue, &event);

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            quitter = true;
        }
    }

    // Nettoyer les ressources
    al_destroy_event_queue(queue);
    al_destroy_display(window.getDisplay());
}