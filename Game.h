#ifndef GAME_H
#define GAME_H

#include "SimonSaysConfig.h"
#include <memory>
#include <array>

class Game{
    
public:
    Game(const std::unique_ptr<SimonSaysConfig>& gameConfig = nullptr)
        : currentGameConfig {gameConfig} {}

    void playGame();

private:
    void generatePattern();
    void showPattern();
    void getUserPattern();
    bool comparePatterns();
    
    bool gameOver = false;
    unsigned int gameRound = 1;
    
    std::string currentPattern {""};
    std::string currentUserPattern {""};

    const static unsigned int patternElementsLength {10};
    const std::array<char, patternElementsLength> patternElements {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    
    const std::unique_ptr<SimonSaysConfig>& currentGameConfig;
};

#endif /* GAME_H */