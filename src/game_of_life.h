#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#define HEIGHT 8
#define WIDTH 8
#define ALIVE true
#define DEAD false

void computeNextGen(bool tab[HEIGHT][WIDTH]);

void computeMultipleGens(bool tab[HEIGHT][WIDTH], unsigned n);

void displayGame(bool tab[HEIGHT][WIDTH]);

#endif // GAME_OF_LIFE_H