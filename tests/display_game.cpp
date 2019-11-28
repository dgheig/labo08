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

	bool game1[WIDTH][WIDTH] = {
		{ALIVE, ALIVE, ALIVE, ALIVE},
		{ALIVE, ALIVE, ALIVE}
	};

	bool game2[WIDTH][WIDTH] = {
		{ALIVE, ALIVE, ALIVE, ALIVE},
		{ALIVE, ALIVE, ALIVE}
	};


	displayGame(game1);
	cout << endl;
	displayGame(game2);

	return exit_value;
}
