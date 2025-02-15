#include "Game.h"

#include <iostream>
#include <memory>
#include <string>
#include <random>
#include <chrono>
#include <thread>

/**
 * @FUNCTION:   Generates a new pattern
 * @PARAMS:     VOID 
 * @RETURNS:    VOID - Sets Game currPattern member 
 */
void Game::generatePattern(void){   
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, patternElementsLength - 1);

    for(int i = 0; i < this->gameRound; i++){
        int newElementIdx = dis(gen);
        this->currentPattern += patternElements[newElementIdx];
    }
}

/**
 * @FUNCTION:   Displays the pattern
 * @PARAM:      VOID
 * @RETURNS:    VOID 
 */
void Game::showPattern(){
    std::cout << "Simon Says to Enter:\n";
    std::cout << this->currentPattern << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(this->currentGameConfig->getTiming()));

    // Clear the console (platform dependent)
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    std::cout << "Simon Says to Enter your Guess:\n";
}

void Game::getUserPattern(){

}

/**
 * @FUNCTION:   Main Game Loop
 * @PARAMS:     VOID
 * @RETURNS:    VOID 
 */
void Game::playGame(void){
    while(!gameOver){
        /* Generate Pattern */
        generatePattern();
        /* Show pattern */
        showPattern();
        /* Allow user to guess pattern */
        break;
        // getUserPattern();
        /* Check pattern vs user input */
        // comparePatterns();
        /* If correct, increase round & score, clean pattern */
        /* Else end game and output score and round */
        
    }
}

