#include "main.hpp"
// TODO 
/**
 * MUSIQUE
 * Classes
 * Appliquer au mieux les concepts vus au cours
 * chaque classe a une fonction draw appelée par la fonction draw de game
 */


int main(){
    init_test(al_init(), "allegro");
    Game game = Game();
    game.runGame();
    return 0;
}