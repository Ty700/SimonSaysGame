#include "SimonSaysConfig.h"
#include "Game.h"

#include <iostream>
#include <memory>

int main(){

   /* Config for Simon Says*/
   auto config = std::make_unique<SimonSaysConfig>();
   
   /* Game */
   auto game = std::make_unique<Game>(config);

   /* Main game loop */
   game->playGame();
}
