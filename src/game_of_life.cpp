#include "game_of_life.h"

using namespace std;

void computeNextGen(bool tab[HEIGHT][WIDTH])
{

}

void displayGame(bool tab[HEIGHT][WIDTH])
{

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
unsigned nbOfNeighbours(int line, int column, bool tab[HEIGHT][WIDTH])
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