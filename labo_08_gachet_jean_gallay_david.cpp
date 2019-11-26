/*
-----------------------------------------------------------------------------------
Laboratoire : Labo_08
Fichier     : labo_08_gachet_jean_gallay_david.cpp
Auteur(s)   : Jean Gachet et David Gallay
Date        : 25.11.2019

But         :
Remarque(s) : Documentation is available under pdf and html format.
                  - doc/doc.pdf
                  - doc/doxy/html/index.html

Compilateur : MinGW-g++ 6.3.0 and g++ 7.4.0
-----------------------------------------------------------------------------------*/
#include <iostream>
#include <cstdlib>
#include "src/game_of_life.h"

int main() {
   #ifdef DEBUG
      std::cout << "Debug is active" << std::endl;
   #endif
   return EXIT_SUCCESS;
}
