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

	bool tab[WIDTH][WIDTH];

   tab[1][3] = ALIVE;
   tab[2][2] = ALIVE;
   tab[2][3] = ALIVE;
   tab[2][4] = ALIVE;
   tab[3][1] = ALIVE;
   tab[3][2] = ALIVE;
   tab[3][3] = ALIVE;
   tab[3][4] = ALIVE;
   tab[3][5] = ALIVE;
   tab[4][2] = ALIVE;
   tab[4][3] = ALIVE;
   tab[4][4] = ALIVE;
   tab[5][3] = ALIVE;

   displayGame(tab);
   computeMultipleGens(tab, 5);

	return exit_value;
}
