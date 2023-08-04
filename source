/*
* Author: Tyler Scotti
* Date: Feb 4, 2023 
* NOTE: THIS WAS WRITTEN VERY EARLY IN MY LEARNING OF C++. DONT MIND THE MISTAKES OR OVERCOMPLICATION OF FUNCTIONS.
* Description: A simple Simon Says game with 3 difficulties
*
* Goals: 
* 3a. Round counter. Round 1 outputs 1 letter. Round 2 outputs 2 letters. To the max number of letters allowed for that difficulty. Rather than it just output all characters at once.
* 3b. Score is based off how many rounds the user got right, and will go to a max of 10 rounds. 
*
*  Completed Goals:
* 1. Convert Simon logic to a function, then call that function in main when it wants to generate pattern. Makes code easier to read
* 2. Make it compute lowercase letters = uppercase letters. Right now it says "M" != "m"
* 4. Add if two neighboring letters are the same, it "rerolls" either letter.
* 5. Situational userScore text based on how many rounds user got right. Ex: User got all 10 rounds right it'll say:
* Great job! You got 10 out of 10 rounds correct! You are now ready to tackle the next difficulty! 
* Rounds 8-10 will be you're ready for next level. 4-7 will be "Great Job". 0-3 will be "Almost there! Keep going!" Something like that
*
*/

#include <string>
#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <iterator>

//Function Declaration
void blank(int num);
std::string patternGen(int dif);
std::string addSpaces(int dif, std::string userPattern);
int testPatterns(std::string userPattern, std::string simonPattern);
void scoreOutput(int userScore, int userIn);


//Global Vars
std::string simonPattern;
std::string userPattern;
int userScore = 0;
int userIn;

int main(){

//Main Vars
   int i;
   srand(time(NULL)); // Random Time for generating random pattern
   blank(100); //Makes output uniformed to the bottom of cmdline

   bool gameOver = false;

//User input
   std::cout << "Choose Difficulty: \n";
   std::cout << "1. Easy \n2. Medium \n3. Hard \n";
   std::cout << "Type the number that corresponds with game difficulty\n";
   std::cin >> userIn;

//Logic Check for valid entry
   while((userIn != 1) && (userIn != 2) && (userIn != 3)){
      std::cout << "Oops, Simon says to just type the number that corresponds with the game difficulty you would like\n";
      std::cin >> userIn;
   }

//Clears Screen
   blank(100);


//Logic for coming up with simon's pattern
   std::cout << "Simon says enter: \n";
   switch (userIn){

      case 1: 
         //Easy Mode pattern gen
         patternGen(1);
         std::cout << simonPattern << "\n";
         _sleep(3500); //Waits 3.5 seconds before clearing screen
         blank(100);
         break;
      case 2:
         //Medium mode pattern gen
         patternGen(2);
         std::cout << simonPattern << "\n";
         _sleep(2500); //Waits 2.5 seconds before clearing screen
         blank(100);
         break;
      case 3:
         //Hard mode pattern gen
         patternGen(3);
         std::cout << simonPattern << "\n";
         _sleep(1500); //Waits 1 second before clearing screen
         blank(100);
         break;
      }

//User's attempt at the pattern
   std::cout<<"Enter Simon's Pattern:\n";
   std::cin >> userPattern;

//If the size of user input size != simon pattern size, it adds spaces to up to simon pattern size
   if(userPattern.size() != simonPattern.size()){
      int i;
      if(userIn == 1){
         int spacesToAdd = 3 - userPattern.size();
         for(i=0; i < spacesToAdd; i++){
            userPattern.append(" ");
         }
      } else if(userIn == 2){
         int spacesToAdd = 5 - userPattern.size();
         for(i=0; i < spacesToAdd; i++){
            userPattern.append(" ");
         }
      } else if(userIn == 3){
         int spacesToAdd = 8 - userPattern.size();
         for(i=0; i < spacesToAdd; i++){
            userPattern.append(" ");
         }
      }
   }

//Test Patterns Logic
   testPatterns(userPattern, simonPattern);

//Output
   
   scoreOutput(userScore, userIn);

  return 0;

}

//Cheeky blank cmd line clear to get rid of simon says entry. User can just scroll up and see the entry again but hopefully they don't realize and just think the screen clears.
void blank(int num){
   int i;
   for(i=0; i<num; i++){
      std::cout << ("\n");
   }
}

//Logic for coming up with simon's pattern
std::string patternGen(int dif){
//Easy Mode pattern gen
   int i;
   if(dif == 1){
      for(i=0; i < 3; i++){
         std::string pattern[4] = {"A", "B", "C", "D"};
         int randIndex = rand() % 3;
         simonPattern.append(pattern[randIndex]);
   //Logic Check for when two characters are the same it'll "reroll" the letter
         if(i>0){  
            while(simonPattern.at(i) == simonPattern.at(i-1)){
               simonPattern.replace(i,1,(pattern[randIndex + 1]));
            }
         }
      } 
   } else if (dif == 2){
      //Medium mode pattern gen
         for(i=0; i<5; i++){
            std::string pattern[6] = {"A", "B", "C", "D", "E", "F"};
            int randIndex = rand() % 5;
            simonPattern.append(pattern[randIndex]);
      //Logic Check for when two characters are the same it'll "reroll" the letter
            if(i>0){
               while(simonPattern.at(i) == simonPattern.at(i-1)){
                simonPattern.replace(i,1,(pattern[randIndex + 1]));
               }
            }
         }
      } else {
         for(i=0; i<8; i++){
         std::string pattern[9] = {"A", "B", "C", "D", "E", "F", "G", "H", "I"};
         int randIndex = rand() % 8;
         simonPattern.append(pattern[randIndex]);
   //Logic Check for when two characters are the same it'll "reroll" the letter
            if(i>0){
            while(simonPattern.at(i) == simonPattern.at(i-1)){
               simonPattern.replace(i,1,(pattern[randIndex + 1]));
               }
            }
         }
      }
   return simonPattern;
}

//Test Patterns Logic 
int testPatterns(std::string userPattern, std::string simonPattern){
   int i;
   for(i=0; i < simonPattern.size(); i++){
      if((userPattern.at(i) != simonPattern.at(i)) && ((userPattern.at(i)-32) != simonPattern.at(i))){
         break;
      } else {
         userScore += 1;
      }
   }
}




//Logic for each difficulties output 
void scoreOutput(int userScore, int userIn){
   std::cout << "Your score is: " << userScore << "\n";

   if(userIn == 1){
      //Easy Outputs
      if(userScore >= 3){
         std::cout << "Amazing Job! I think you're ready for the next level!";
      } else if(userScore == 2){
         std::cout << "Good Job! Almost ready for the next level!";
      } else {
         std::cout << "Gah. Better luck next time!";
      }
   } else if(userIn == 2){
      if(userScore > 4){
         std::cout << "Amazing Job! I think you're ready for the next level!";
      } else if((userScore >= 2) && (userScore <= 3)){
         std::cout << "Good Job! Almost ready for the next level!";
      } else {
         std::cout << "Gah. Better luck next time!";
      }
   } else if(userIn == 3){
      if(userScore == 10){
         std::cout << "Amazing Job! You beat the game!";
      } else if(userScore > 7){
         std::cout << "Amazing Job! Just a tad bit further!";
      } else if((userScore <= 7) && (userScore > 4)){
         std::cout << "Good Job!! You're almost there!";
      } else {
         std::cout << "Gah. Better luck next time!";
      }
   }
}
