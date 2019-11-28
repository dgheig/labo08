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
 * Returns the char to display depending on the cell's state.
 * @param value cell's state
 * @return character to display
 */
char getDisplayChar(bool value);

/**
 * Copys the first array into the second array.
 * @param fromArray origin array
 * @param toArray target array
 */
void copyTab(bool fromArray[HEIGHT][WIDTH], bool toArray[HEIGHT][WIDTH]);

void preFillGame(bool game[HEIGHT][WIDTH])
{
   for(size_t line = 0; line < HEIGHT; ++line)
   {
      for(size_t column = 0; column < WIDTH; ++column)
      {
         game[line][column] = DEAD;
      }
   }
}

bool computeNextGen(bool currentGen[HEIGHT][WIDTH])
{
   bool newGen[HEIGHT][WIDTH];
   unsigned neighbours;
   bool changeDetected = false;  //is new gen different from current gen

   for (size_t line = 0; line < HEIGHT; ++line)
   {
      for (size_t column = 0; column < WIDTH; ++column)
      {
         neighbours = nbOfNeighbours(currentGen, line, column);

         //new state of cell
         if (neighbours == 3)
         {
            newGen[line][column] = ALIVE;
         }
         else if (neighbours == 2 && currentGen[line][column] == ALIVE)
         {
            newGen[line][column] = ALIVE;
         }
         else
         {
            newGen[line][column] = DEAD;
         }

         //detection of changes
         if (currentGen[line][column] != newGen[line][column])
         {
            changeDetected = true;

            #ifdef DEBUG
            if(newGen[line][column] == ALIVE)
               cout << "tab[" << line << "][" << column << "] = "
                    << neighbours << " => naissance" << endl;
            else
               cout << "tab[" << line << "][" << column << "] = "
                    << neighbours << " => mort" << endl;
            #endif

         }

         #ifdef DEBUG
         else if(newGen[line][column] == ALIVE)
            cout << "tab[" << line << "][" << column << "] = "
                 << neighbours << " => survie" << endl;
         #endif

      }
   }

   copyTab(newGen, currentGen);  //sets new state as current state

   return changeDetected;
}


void computeMultipleGens(bool currentGen[HEIGHT][WIDTH], unsigned n)
{
   bool computeNext = true;   //continue computation only if changes are still happening

   //computes and displays n generations
   for(unsigned iteration = 0; iteration < n && computeNext; ++iteration)
   {
      computeNext = computeNextGen(currentGen);
      displayGame(currentGen);
      cout << endl;
   }
}

void displayGame(const bool game[HEIGHT][WIDTH])
{
   //display of columns number
   print << ' ';
   for(size_t column = 0; column < WIDTH; ++column)
   {
      print << column;
   }
   cout << endl;

   //display of each line with line number
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

unsigned nbOfNeighbours(bool game[HEIGHT][WIDTH], int line, int column)
{
   unsigned neighbours = 0;   //nb of neighbours

   //boundaries of neighbours indexes
   size_t lineStart   = line - 1   > 0          ? line - 1   : 0;          // MAX
   size_t lineStop    = line + 1   < HEIGHT - 1 ? line + 1   : HEIGHT - 1; // MIN
   size_t columnStart = column - 1 > 0          ? column - 1 : 0;          // MAX
   size_t columnStop  = column + 1 < WIDTH - 1  ? column + 1 : WIDTH - 1;  // MIN

   //for all neighbours, including self
   for (size_t lineIndex = lineStart ; lineIndex <= lineStop; ++lineIndex)
   {
      for (size_t columnIndex = columnStart; columnIndex <= columnStop; ++columnIndex)
      {
         if(game[lineIndex][columnIndex] == ALIVE)
	    ++neighbours;
      }
   }

   if(game[line][column] == ALIVE) --neighbours;   //adjustment for self

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

void copyTab(bool fromArray[HEIGHT][WIDTH], bool toArray[HEIGHT][WIDTH])
{
   for(size_t line = 0; line < HEIGHT; ++line)
   {
      for(size_t column = 0; column < WIDTH; ++column)
      {
         toArray[line][column] = fromArray[line][column];
      }
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