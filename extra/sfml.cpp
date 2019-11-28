#include <SFML/Graphics.hpp>
#include "../src/game_of_life.h"
#include <iostream>
using namespace std;

#define RECT_HEIGHT 50
#define RECT_WIDTH  RECT_HEIGHT
#define BORDER 3

sf::RenderWindow window (sf::VideoMode(RECT_HEIGHT * HEIGHT, RECT_WIDTH * WIDTH), "My window");
sf::RectangleShape alive (sf::Vector2f(RECT_HEIGHT, RECT_WIDTH));
sf::RectangleShape dead (sf::Vector2f(RECT_HEIGHT, RECT_WIDTH));


void display(bool currentGen[HEIGHT][WIDTH])
{

   window.clear(sf::Color::White);
   //display of each line with line number
   for(size_t line = 0; line < HEIGHT; ++line)
   {
      for(size_t column = 0; column < WIDTH; ++column)
      {
         switch (currentGen[line][column])
         {
            case ALIVE:
               alive.setPosition(RECT_HEIGHT * line, RECT_WIDTH * column);
               window.draw(alive);
               #ifdef DEBUG2
               cout << "case ALIVE at line; " << line << "and column:" << column << endl;
               cout << "   Rendered at " << RECT_HEIGHT * line << " - " << RECT_WIDTH * column << endl;
               #endif
               break;
            default:
               dead.setPosition(RECT_HEIGHT * line, RECT_WIDTH * column);
               window.draw(dead);
               break;
         }
      }
   }

   window.display();
}

void wait()
{
   // check all the window's events that were triggered since the last iteration of the loop
   sf::Event event;
   bool wait = true;
   while(wait and window.isOpen())
   {
      #ifdef DEBUG2
      cout << "Waiting left arrow input" << endl;
      #endif
      while (window.pollEvent(event))
      {
         // "close requested" event: we close the window
         if (event.type == sf::Event::Closed)
               window.close();
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
         {
            wait = false;
         }
      }
   }
}

int main()
{
   alive.setFillColor(sf::Color::Red);
   dead.setFillColor(sf::Color::White);
   alive.setOutlineColor(sf::Color::Black);
   dead.setOutlineColor(sf::Color::Black);
   alive.setOutlineThickness(BORDER);
   dead.setOutlineThickness(BORDER);
   int n = 100;
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

   //computes and displays n generations
   display(currentGen);
   // for(unsigned iteration = 0; window.isOpen() and iteration < n and computeNextGen(currentGen); ++iteration)
   // {
   //    wait(); // Wait for left arrow being pressed
   //    display(currentGen);
   //    cout << "Rendered" << endl;
   // }
   while(window.isOpen())
   {
      sf::Event event;
      bool wait = true;
      #ifdef DEBUG2
      cout << "Waiting left arrow input" << endl;
      #endif
      while (window.pollEvent(event))
      {
         // "close requested" event: we close the window
         if (event.type == sf::Event::Closed)
               window.close();
      }
      computeNextGen(currentGen);
      display(currentGen);
      cout << "Rendered" << endl;
   }
   window.close();
   return 0;
}