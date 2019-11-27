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

   tab[2][4] = ALIVE;
   tab[3][3] = ALIVE;
   tab[3][4] = ALIVE;
   tab[3][5] = ALIVE;
   tab[4][2] = ALIVE;
   tab[4][3] = ALIVE;
   tab[4][4] = ALIVE;
   tab[4][5] = ALIVE;
   tab[4][6] = ALIVE;
   tab[5][3] = ALIVE;
   tab[5][4] = ALIVE;
   tab[5][5] = ALIVE;
   tab[6][4] = ALIVE;

   computeMultipleGens(tab, 5);

	return exit_value;
}