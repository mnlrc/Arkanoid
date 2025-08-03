/**
 * @file main.cpp
 * @author Manuel Rocca
 * @brief Source file for the main function
 * @date 2024
 *
 */

#include "game.hpp"
// TODO
/**
 * MUSIQUE
 * Classes
 * Appliquer au mieux les concepts vus au cours
 * chaque classe a une fonction draw appelée par la fonction draw de game
 * RETIRER LES NOMS DE VARIABLES DANS LES DECLARATIONS, SEULEMENT LAISSER LES TYPES ?
 *
 * IDEES: - hp de briques pour déterminer si elle est cassable
 *        - compteur de briques cassées pour éviter de galérer le vecteur
 */

int main()
{
    Game game = Game();
    game.runGame();
    return 0;
}