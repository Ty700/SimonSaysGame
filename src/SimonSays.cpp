/**
 * This is a refactor of my first ever C++ project, SimonSays, similar to my TicTacToe refactor.
 * I originally started this project back in 2023. It's enjoyable to revisit and improve it,
 * reflecting on how my coding skills have evolved since then.
 * 
 * If you're interested in the original 2023 version, check out the other branch. Please be kind with your critiques.
 */

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
