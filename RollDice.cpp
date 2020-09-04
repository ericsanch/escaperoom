//  finalProject - Escape Room
//  RollDice.cpp
//  Eric Sanchez
//  12/10/19
//
//  This file contains the functions of the RollDice room. This includes
//  a constructor which creates a letter object and the event function
//  for the user to roll dice against the computer.
//

#include "RollDice.hpp"

//constructor, pass letter as string to create room
RollDice::RollDice(std::string val){
  visited = false;
  letter = new Letters(val);
}

//destructor, check if room has been visited and delete letter if necessary
RollDice::~RollDice(){
  if (visited == false){
    delete letter;
  }
}

//event takes the player's items stack by reference, checks if the room has
//been visited and runs the function. Adds letter to the player's
//stack if they win.
bool RollDice::event(std::stack<Items*> & playerItems){
  if (visited == true){
    return true;
  }
  else{
    int opponentRoll = (rand() % 6) + 1;
    int playerRoll;
    char junk;
    std::cout << "..............................." << '\n'
              << "You encountered a dice-rolling champ." << '\n'
              << "If you roll a higher number than him, you will get a letter." << '\n'
              << "Press enter to roll";
              
    std::cin.ignore( 0, '\n' );
    std::cin.get(junk);
    std::cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );

    playerRoll = (rand() % 6) + 1;
    std::cout << "You rolled " << playerRoll << '\n';
    std::cout << "Your opponent rolled " << opponentRoll << '\n';
    if (playerRoll > opponentRoll){
      std::cout << "You win, picked up letter " << letter->getItemName() << '\n';
      visited = true;
      playerItems.push(letter);
      letter = nullptr;
      return true;
    }
    else if (playerRoll < opponentRoll){
      std::cout << "You Lose, come back to try again" << '\n';
      return false;
    }
    else if (playerRoll == opponentRoll){
      std::cout << "It's a tie, come back to try again" << '\n';
      return false;
    }
    //this case should never be reached. Return statement included
    //to prevent getting compile warnings.
    std::cout << "Shouldn't be here, check results." << '\n';
    return false;
  }
}
