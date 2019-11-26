#include "game_of_life.h"
#include <iostream>
#include <iomanip>

using namespace std;

char get_display_char(bool value) {
    switch (value)
    {
    case ALIVE:
        return 'X';
    case DEAD:
        return 'O';
    }
    return 'O';
}

void computeNextGen(bool tab[HEIGHT][WIDTH])
{

    #ifdef DEBUG

    #endif
}


void computeMultipleGens(unsigned n, bool tab[HEIGHT][WIDTH])
{
    for(int iteration = 0; iteration < n; ++iteration)
    {
        computeNextGen(tab);
        displayGame(tab);
    }
}

void displayGame(bool tab[HEIGHT][WIDTH])
{

    using std::cout;
    using std::endl;
    #define print cout << setw(3)
    for(size_t column = 0; column < WIDTH; ++column) print << column;
    cout << endl;
    for(size_t line = 0; line < HEIGHT; ++line)
    {
        print << line;
        for(size_t column = 0; column < WIDTH; ++column)
        {
            print << get_display_char(tab[line][column]);
        }
        cout << endl;
    }
}


unsigned nbOfNeighbours(int line, int column, bool tab[HEIGHT][WIDTH])
{
   unsigned neighbours = 0;
   for (int l = -1; l <= 1; ++l)       //
   {                                   //for all neighbours
      for (int c = -1; c <= 1; ++c)    //
      {
         if ( !(l == 0 && c == 0 ) &&                    //exluding self
              line + l >= 0 && column + c >= 0 &&        //excluding underflow
              line + l < HEIGHT && column + c < WIDTH )  //excluding overflow
         {
            neighbours += (unsigned)tab[line - l][column - c];
         }
      }
   }
   return neighbours;
}

/*
unsigned nbOfNeighbours(size_t line, size_t column, bool tab[HEIGHT][WIDTH])
{
    unsigned neigbhours = 0;
    if(line < HEIGHT - 1 and tab[line + 1][column] == ALIVE) {
        ++neigbhours;
    }
    if(line > 1 and tab[line - 1][column] == ALIVE) {
        ++neigbhours;
    }
    if(column < WIDTH - 1 and tab[line][column + 1] == ALIVE) {
        ++neigbhours;
    }
    if(line > 1 and tab[line][column - 1] == ALIVE) {
        ++neigbhours;
    }
    return neigbhours;
}*/