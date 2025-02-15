#ifndef SIMON_SAYS_CONFIG_H
#define SIMON_SAYS_CONFIG_H

#include <iostream>

class SimonSaysConfig {

public:
    SimonSaysConfig(){
        setDifficulty();
        setTiming();   
    }

    int getDifficulty() const       { return this->difficulty; }
    unsigned int getTiming() const  { return this->timing; }

private:
    void setDifficulty();
    void setTiming();

    int difficulty {-1};
    
    /* Milliseconds */
    const int LOW_DIFFICULTY    = 1;
    constexpr static unsigned int LOW_TIMING    {3500};
    
    const int MEDIUM_DIFFICULTY = 2;
    constexpr static unsigned int MEDIUM_TIMING {2500};
    
    const int HIGH_DIFFICULTY   = 3;
    constexpr static unsigned int HARD_TIMING   {1500};

    unsigned int timing {LOW_TIMING};
};

#endif /* SIMON_SAYS_CONFIG_H*/