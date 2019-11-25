#include "grid.h"

/*
    A grid is a virtual bi-dimensional C-Array of char.
    Heigth is its number of line,
    Width is its number of column

*/

// PROTOTYPES
unsigned get_grid_index(unsigned line, unsigned col);
char get_grid_value(char grid[], unsigned line, unsigned col);


// CODES
unsigned get_grid_index(unsigned line, unsigned col) {
    return line * WIDTH + col;
}

char get_grid_value(unsigned line, unsigned col) {
    return GAME_GRID[get_grid_index(line, col)];
}