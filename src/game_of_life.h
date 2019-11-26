#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#define HEIGHT 9
#define WIDTH 9
#define ALIVE true
#define DEAD false
#define ALIVE_CHAR 'X'
#define DEAD_CHAR 'O'

/**
 * Take a game and computes the next generation.
 * @param tab current state of the game, modified to the new state of the game
 * @return if a change occured
 */
bool computeNextGen(bool tab[HEIGHT][WIDTH]);

/**
 * Take a game and computes the n next generations (stops if a stable state is reached).
 * Displays the game after each generation.
 * @param tab [IN]current state of the game, modified to the new state of the game
 * @param n
 */
void computeMultipleGens(bool tab[HEIGHT][WIDTH], unsigned n);

/**
 * 
 * @param tab
 */
void displayGame(bool tab[HEIGHT][WIDTH]);

#endif // GAME_OF_LIFE_H