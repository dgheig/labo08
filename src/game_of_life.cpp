#include "game_of_life.h"
#include <iostream>
#include <iomanip>

using namespace std;
#define print cout << setw(3)

unsigned nbOfNeighbours(bool tab[HEIGHT][WIDTH], int line, int column);

char getDisplayChar(bool value);
void copyTab(bool fromTab[HEIGHT][WIDTH], bool toTab[HEIGHT][WIDTH]);



bool computeNextGen(bool tab[HEIGHT][WIDTH])
{
   bool newGen[HEIGHT][WIDTH];
   bool newValue;
   unsigned neighbours;
   bool changeDetected = false;

   for (size_t line = 0; line < HEIGHT; ++line)
   {
      for (size_t column = 0; column < WIDTH; ++column)
      {
         neighbours = nbOfNeighbours(tab, line, column);
         if (neighbours == 3)
         {
            newValue = ALIVE;
         }
         else if (neighbours == 2 && tab[line][column] == ALIVE)
         {
            newValue = ALIVE;
         }
         else
         {
            newValue = DEAD;
         }

         if (tab[line][column] != newValue)
         {
            changeDetected = true;
				#ifdef DEBUG
					if(newValue == ALIVE)
						cout << "tab[" << line << "][" << column << "] = " << neighbours << " => naissance" << endl;
					else
						cout << "tab[" << line << "][" << column << "] = " << neighbours << " => mort" << endl;
				#endif
         }
			#ifdef DEBUG
				else if(newValue == ALIVE)
					cout << "tab[" << line << "][" << column << "] = " << neighbours << " => survie" << endl;
			#endif

         newGen[line][column] = newValue;
      }
   }


   copyTab(newGen, tab);

   return changeDetected;
}


void computeMultipleGens(bool tab[HEIGHT][WIDTH], unsigned n)
{
    for(unsigned iteration = 0; iteration < n; ++iteration)
    {
        computeNextGen(tab);
        displayGame(tab);
    }
}

void displayGame(bool tab[HEIGHT][WIDTH])
{
   print << ' ';
   for(size_t column = 0; column < WIDTH; ++column) print << column + 1;
   cout << endl;
   for(size_t line = 0; line < HEIGHT; ++line)
   {
      print << line + 1;
      for(size_t column = 0; column < WIDTH; ++column)
      {
          print << getDisplayChar(tab[line][column]);
      }
      cout << endl;
   }
}


unsigned nbOfNeighbours(bool tab[HEIGHT][WIDTH], int line, int column)
{
   unsigned neighbours = 0;
   for (int lineShift = -1; lineShift <= 1; ++lineShift)             //
   {                                                                 //for all neighbours
      for (int columnShift = -1; columnShift <= 1; ++columnShift)    //
      {
         if ( !(lineShift == 0 && columnShift == 0 ) &&                    //exluding self
              line + lineShift >= 0 && column + columnShift >= 0 &&        //excluding underflow
              line + lineShift < HEIGHT && column + columnShift < WIDTH )  //excluding overflow
         {
            neighbours += (unsigned)tab[line + lineShift][column + columnShift];
         }
      }
   }
   return neighbours;
}

char getDisplayChar(bool value)
{
    switch (value)
    {
      case ALIVE:
         return ALIVE_CHAR;
      case DEAD:
         return DEAD_CHAR;
    }
    return DEAD_CHAR;
}


void copyTab(bool fromTab[HEIGHT][WIDTH], bool toTab[HEIGHT][WIDTH])
{
   for(size_t line = 0; line < HEIGHT; ++line)
   {
      for(size_t column = 0; column < WIDTH; ++column)
      {
          toTab[line][column] = fromTab[line][column];
      }
   }
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