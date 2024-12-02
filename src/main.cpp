/**
 * @file main.cpp
 * @author Manuel Rocca
 * @brief Source file for the main function
 * @date 2024
 *
 */

#include "main.hpp"
// TODO 
/**
 * MUSIQUE
 * Classes
 * Appliquer au mieux les concepts vus au cours
 * chaque classe a une fonction draw appelée par la fonction draw de game
 * RETIRER LES NOMS DE VARIABLES DANS LES DECLARATIONS, SEULEMENT LAISSER LES TYPES
 */


int main(){
    Game game = Game(View());
    game.runGame();
    return 0;
}