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
}

/**
 * @FUNCTION:    Gathers the user's guess 
 * @PARAMS:      VOID 
 * @RETURNS:     VOID - Sets Game's member currentUserPattern 
 */
void Game::getUserPattern(){
    std::cout << "Simon Says to Enter your Guess:\n";
    std::cin >> this->currentUserPattern;
}

/**
 * @FUNCTION:   Converts a given string to all lowercase (and might do more later)
 * @PARAMS:     A string 
 * @RETURNS:    VOID 
 */
void sanatizePatterns(std::string& ptrn){
    for(int i = 0; i < ptrn.length(); i++){
        ptrn[i] = tolower(ptrn[i]);
    }
}

/**
 * @FUNCTION:   Compares current pattern to user's pattern 
 * @PARAMS:     VOID 
 * @RETURNS:    True -> If patterns are the same | False -> if patterns are not the same 
 */
bool Game::comparePatterns(){
    if(this->currentPattern.length() != this->currentUserPattern.length()){
        return false;
    }

    sanatizePatterns(this->currentPattern);
    sanatizePatterns(this->currentUserPattern);

    std::cout << this->currentPattern << std::endl;
    std::cout << this->currentUserPattern<< std::endl;
    
    for(int i = 0; i < this->currentPattern.length(); i++){
        if(this->currentPattern[i] != this->currentUserPattern[i]){
            return false;
        }
    }

    return true;
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
        getUserPattern();
        /* Check pattern vs user input */
        
        /* If correct, increase round & score, clean pattern */
        if(comparePatterns()){
            this->currentPattern = "";
            this->currentUserPattern = "";
            this->gameRound += 1;
        } else {
            /* Else end game and output score and round */
            gameOver = true;
            // outputScore();
        }
    }
}

