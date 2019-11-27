#include "game_of_life.h"
#include <iostream>
#include <iomanip>

using namespace std;
#define print cout << setw(3)

/**
 * Compute the number of neighbours of a cell.
 * @param game
 * @param line cell's line
 * @param column cell's column
 * @return 
 */
unsigned nbOfNeighbours(bool game[HEIGHT][WIDTH], int line, int column);

/**
 * Returns the char to display depending on the cell state.
 * @param value cell state
 * @return char to display
 */
char getDisplayChar(bool value);

/**
 * Copys the first tab into the second tab.
 * @param fromTab origin tab
 * @param toTab target tab
 */
void copyTab(bool fromTab[HEIGHT][WIDTH], bool toTab[HEIGHT][WIDTH]);



bool computeNextGen(bool currentGen[HEIGHT][WIDTH])
{
   bool newGen[HEIGHT][WIDTH];
   bool newValue;
   unsigned neighbours;
   bool changeDetected = false;

   for (size_t line = 0; line < HEIGHT; ++line)
   {
      for (size_t column = 0; column < WIDTH; ++column)
      {
         neighbours = nbOfNeighbours(currentGen, line, column);
         if (neighbours == 3)
         {
            newValue = ALIVE;
         }
         else if (neighbours == 2 && currentGen[line][column] == ALIVE)
         {
            newValue = ALIVE;
         }
         else
         {
            newValue = DEAD;
         }

         if (currentGen[line][column] != newValue)
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


   copyTab(newGen, currentGen);

   return changeDetected;
}


void computeMultipleGens(bool currentGen[HEIGHT][WIDTH], unsigned n)
{
   for(unsigned iteration = 0; iteration < n; ++iteration)
   {
      if (!computeNextGen(currentGen))
      {
         return;
      }
      displayGame(currentGen);
   }
}

void displayGame(const bool game[HEIGHT][WIDTH])
{
   print << ' ';
   for(size_t column = 0; column < WIDTH; ++column) print << column;
   cout << endl;
   for(size_t line = 0; line < HEIGHT; ++line)
   {
      print << line;
      for(size_t column = 0; column < WIDTH; ++column)
      {
          print << getDisplayChar(game[line][column]);
      }
      cout << endl;
   }
}

/*
unsigned nbOfNeighbours(bool game[HEIGHT][WIDTH], int line, int column)
{
   unsigned neighbours = 0;
   for (int lineShift = -1; lineShift <= 1; ++lineShift)             //
   {                                                                 //for all neighbours
      for (int columnShift = -1; columnShift <= 1; ++columnShift)    //
      {
         if ( line + lineShift >= 0 && column + columnShift >= 0 &&        //excluding underflow
              line + lineShift < HEIGHT && column + columnShift < WIDTH )  //excluding overflow
         {
            neighbours += (unsigned)game[line + lineShift][column + columnShift];
         }
      }
   }
   if(game[line][column] == ALIVE) --neighbours;
   return neighbours;
}*/

unsigned nbOfNeighbours(bool game[HEIGHT][WIDTH], int line, int column)
{
   unsigned neighbours = 0;
   unsigned lineStart = line - 1 > 0 ? line - 1 : 0; // MAX
   unsigned lineStop = line + 1 < HEIGHT - 1 ? line + 1 : HEIGHT - 1; // MIN
   unsigned columnStart = column - 1 > 0 ? column - 1 : 0; // MAX
   unsigned columnStop = column + 1 < WIDTH - 1 ? column + 1 : WIDTH - 1; MIN(WIDTH - 1, column + 1); // MIN

   for (int lineIndex = lineStart ; lineIndex <= lineStop; ++lineIndex)
   {
      for (int columnIndex = columnStart; columnIndex <= columnStop; ++columnIndex)
      {
         neighbours += (unsigned)game[lineIndex][columnIndex];
      }
   }
   if(game[line][column] == ALIVE) --neighbours;
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
