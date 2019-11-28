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

using namespace std;

#define EMPTY_BUFFER while(cin.get()!='\n')

int main() {
   #ifdef DEBUG
      cout << "Debug is active" << endl;
   #endif
      
   bool game[HEIGHT][WIDTH] = { { DEAD , DEAD , DEAD , DEAD , DEAD , DEAD , DEAD , DEAD , DEAD  },
                                { DEAD , DEAD , DEAD , DEAD , DEAD , DEAD , DEAD , DEAD , DEAD  },
                                { DEAD , DEAD , DEAD , DEAD , DEAD , DEAD , DEAD , DEAD , DEAD  },
                                { DEAD , DEAD , DEAD , DEAD , ALIVE, DEAD , DEAD , DEAD , DEAD  },
                                { DEAD , DEAD , DEAD , ALIVE, ALIVE, ALIVE, DEAD , DEAD , DEAD  },
                                { DEAD , DEAD , DEAD , DEAD , ALIVE, DEAD , DEAD , DEAD , DEAD  },
                                { DEAD , DEAD , DEAD , DEAD , DEAD , DEAD , DEAD , DEAD , DEAD  },
                                { DEAD , DEAD , DEAD , DEAD , DEAD , DEAD , DEAD , DEAD , DEAD  },
                                { DEAD , DEAD , DEAD , DEAD , DEAD , DEAD , DEAD , DEAD , DEAD  }};
   
   displayGame(game);
   computeMultipleGens(game, 10);
   
   EMPTY_BUFFER;
   return EXIT_SUCCESS;
}
