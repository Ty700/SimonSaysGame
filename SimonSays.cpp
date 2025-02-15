#include "SimonSaysConfig.h"

#include <iostream>
#include <memory>

//Function Declaration
std::string patternGen(int dif);
int testPatterns(std::string userPattern, std::string simonPattern);

int main(){

   /* Config for Simon Says*/
   auto config = std::make_unique<SimonSaysConfig>();
   

   return 0;
}

// //Logic for coming up with simon's pattern
//    std::cout << "Simon says enter: \n";
//    switch (userIn){

//       case 1: 
//          //Easy Mode pattern gen
//          patternGen(1);
//          std::cout << simonPattern << "\n";
//          _sleep(3500); //Waits 3.5 seconds before clearing screen
//          blank(100);
//          break;
//       case 2:
//          //Medium mode pattern gen
//          patternGen(2);
//          std::cout << simonPattern << "\n";
//          _sleep(2500); //Waits 2.5 seconds before clearing screen
//          blank(100);
//          break;
//       case 3:
//          //Hard mode pattern gen
//          patternGen(3);
//          std::cout << simonPattern << "\n";
//          _sleep(1500); //Waits 1 second before clearing screen
//          blank(100);
//          break;
//       }

// //User's attempt at the pattern
//    std::cout<<"Enter Simon's Pattern:\n";
//    std::cin >> userPattern;

// //If the size of user input size != simon pattern size, it adds spaces to up to simon pattern size
//    if(userPattern.size() != simonPattern.size()){
//       int i;
//       if(userIn == 1){
//          int spacesToAdd = 3 - userPattern.size();
//          for(i=0; i < spacesToAdd; i++){
//             userPattern.append(" ");
//          }
//       } else if(userIn == 2){
//          int spacesToAdd = 5 - userPattern.size();
//          for(i=0; i < spacesToAdd; i++){
//             userPattern.append(" ");
//          }
//       } else if(userIn == 3){
//          int spacesToAdd = 8 - userPattern.size();
//          for(i=0; i < spacesToAdd; i++){
//             userPattern.append(" ");
//          }
//       }
//    }

//Test Patterns Logic
   // testPatterns(userPattern, simonPattern);

//Output
   
   // scoreOutput(userScore, userIn);

//   return 0;

// }


// //Logic for coming up with simon's pattern
// std::string patternGen(int dif){
// //Easy Mode pattern gen
//    int i;
//    if(dif == 1){
//       for(i=0; i < 3; i++){
//          std::string pattern[4] = {"A", "B", "C", "D"};
//          int randIndex = rand() % 3;
//          simonPattern.append(pattern[randIndex]);
//    //Logic Check for when two characters are the same it'll "reroll" the letter
//          if(i>0){  
//             while(simonPattern.at(i) == simonPattern.at(i-1)){
//                simonPattern.replace(i,1,(pattern[randIndex + 1]));
//             }
//          }
//       } 
//    } else if (dif == 2){
//       //Medium mode pattern gen
//          for(i=0; i<5; i++){
//             std::string pattern[6] = {"A", "B", "C", "D", "E", "F"};
//             int randIndex = rand() % 5;
//             simonPattern.append(pattern[randIndex]);
//       //Logic Check for when two characters are the same it'll "reroll" the letter
//             if(i>0){
//                while(simonPattern.at(i) == simonPattern.at(i-1)){
//                 simonPattern.replace(i,1,(pattern[randIndex + 1]));
//                }
//             }
//          }
//       } else {
//          for(i=0; i<8; i++){
//          std::string pattern[9] = {"A", "B", "C", "D", "E", "F", "G", "H", "I"};
//          int randIndex = rand() % 8;
//          simonPattern.append(pattern[randIndex]);
//    //Logic Check for when two characters are the same it'll "reroll" the letter
//             if(i>0){
//             while(simonPattern.at(i) == simonPattern.at(i-1)){
//                simonPattern.replace(i,1,(pattern[randIndex + 1]));
//                }
//             }
//          }
//       }
//    return simonPattern;
// }

// //Test Patterns Logic 
// int testPatterns(std::string userPattern, std::string simonPattern){
//    int i;
//    for(i=0; i < simonPattern.size(); i++){
//       if((userPattern.at(i) != simonPattern.at(i)) && ((userPattern.at(i)-32) != simonPattern.at(i))){
//          break;
//       } else {
//          userScore += 1;
//       }
//    }
// }
