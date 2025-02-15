#include "SimonSaysConfig.h"


/** 
 * @FUNCTION:   Sets difficult for Simon Says
 * @PARAMS:     VOID
 * @RETURNS:    VOID - Sets SimonSaysConfig difficulty member to user selected difficulty (1 - 3)
 */
void SimonSaysConfig::setDifficulty(void){    
    int userIn {-1};
    //User input
    std::cout << "Choose Difficulty: \n";
    std::cout << "1. Easy \n2. Medium \n3. Hard \n";
    std::cout << "Type the number that corresponds with game difficulty\n";
    std::cin >> userIn;

    //Logic Check for valid entry
    while(userIn < LOW_DIFFICULTY || userIn > HIGH_DIFFICULTY){
        std::cout << "Oops, Simon says to just type the number that corresponds with the game difficulty you would like\n";
        std::cin >> userIn;
    }

    this->difficulty = userIn;
}

/** 
 * @FUNCTION:   Sets the time SimonSaysConfig timing member based on game's difficulty
 * @PARAMS:     VOID
 * @RETURNS:    VOID - Sets SimonSaysConfig timing member 
 */
void SimonSaysConfig::setTiming(){
    switch(this->difficulty){
        case 1:
            this->timing = LOW_TIMING;
            break;
        case 2:
            this->timing = MEDIUM_TIMING;
            break;
        case 3:
            this->timing = HARD_TIMING;
            break;
        default:
            std::cout << "Err: setTiming" << std::endl;
            this->timing = LOW_TIMING;
    }
}