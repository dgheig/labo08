#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#define HEIGHT 8
#define WIDTH 8
#define ALIVE true
#define DEAD false

/**
 * Take a game and computes the next generation.
 * @param tab current state of the game, modified to the new state of the game
 * @return if a change occured
 */
bool computeNextGen(bool tab[HEIGHT][WIDTH]);

/**
 * Take a game and computes the n next generations.
 * @param tab 
 * @param n
 */
void computeMultipleGens(bool tab[HEIGHT][WIDTH], unsigned n);

/**
 * 
 * @param tab
 */
void displayGame(bool tab[HEIGHT][WIDTH]);

#endif // GAME_OF_LIFE_H