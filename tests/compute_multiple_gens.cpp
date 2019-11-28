/*
-----------------------------------------------------------------------------------
Laboratoire : Labo_08
Fichier     : model.cpp
Auteur(s)   : Jean Gachet et David Gallay
Date        : 25.11.2019

But         : Example of test file for a function
Remarque(s) :
Compilateur :
-----------------------------------------------------------------------------------*/

#include <iostream>
#include "../src/game_of_life.h"
using namespace std;

int exit_value = EXIT_SUCCESS;

int main() {


	bool currentGen[HEIGHT][WIDTH];
   preFillGame(currentGen);

   currentGen[2][4] = ALIVE;
   currentGen[3][3] = ALIVE;
   currentGen[3][4] = ALIVE;
   currentGen[3][5] = ALIVE;
   currentGen[4][2] = ALIVE;
   currentGen[4][3] = ALIVE;
   currentGen[4][4] = ALIVE;
   currentGen[4][5] = ALIVE;
   currentGen[4][6] = ALIVE;
   currentGen[5][3] = ALIVE;
   currentGen[5][4] = ALIVE;
   currentGen[5][5] = ALIVE;
   currentGen[6][4] = ALIVE;

   displayGame(currentGen);
   computeMultipleGens(currentGen, 700);

	return exit_value;
}
