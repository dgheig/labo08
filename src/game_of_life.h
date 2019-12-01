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
 * @param currentGen [IN]  current state of the game
 *                   [OUT] new state of the game
 * @return if a change occured
 */
bool computeNextGen(bool currentGen[HEIGHT][WIDTH]);

/**
 * Take a game and computes the n next generations (stops if a stable state is reached).
 * Displays the game after each generation.
 * @param currentGen [IN]  current state of the game
 *                   [OUT] new state of the game
 * @param n   number of generations to compute
 * @param autoStop stops if no more changes are detected between generations
 */
void computeMultipleGens(bool currentGen[HEIGHT][WIDTH], unsigned n, bool autoStop = true);

/**
 * Display the game.
 * @param game
 */
void displayGame(const bool game[HEIGHT][WIDTH]);

void preFillGame(bool game[HEIGHT][WIDTH]);

#endif // GAME_OF_LIFE_H
