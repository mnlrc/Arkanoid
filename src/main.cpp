#include <iostream>
#include "allegro_test.hpp"
#include "game.hpp"

// TODO 
/**
 * MUSIQUE
 * Classes
 * Appliquer au mieux les concepts vus au cours
 */


int main(){
    init_test(al_init(), "allegro");
    Game game = Game();
    game.runGame();
    return 0;
}