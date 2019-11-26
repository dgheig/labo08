#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#define HEIGHT 8
#define WIDTH 8
#define ALIVE true
#define DEAD false

void computeNextGen(bool tab[HEIGHT][WIDTH]);

void computeMultipleGens(unsigned n, bool tab[HEIGHT][WIDTH]);

void displayGame(bool tab[HEIGHT][WIDTH]);

#endif // GAME_OF_LIFE_H