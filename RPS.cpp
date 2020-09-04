//  finalProject - Escape Room
//  RPS.cpp
//  Eric Sanchez
//  12/10/19
//
//  This file contains the function definitions used by the RPS space
//  including a constructor which sets up the RPS heirarchy, destructor
//  which deletes each node of the heirarchy, and the event which lets
//  the player select what they want to throw and checks for the winner.
//  The circular linked list is used since RPS is has a circular winning
//  layout.
//

#include "RPS.hpp"

//constructor, takes val as a string to make the letter object.
RPS::RPS(std::string val){
  rock = new RPSOptions;
  paper = new RPSOptions;
  scissors = new RPSOptions;

  userThrow = NULL;
  compThrow = NULL;
  visited = false;
  letter = new Letters(val);
  
  rock->beats = scissors;
  rock->loses = paper;
  rock->option = "rock";
  paper->beats = rock;
  paper->loses = scissors;
  paper->option = "paper";
  scissors->beats = paper;
  scissors->loses = rock;
  scissors->option = "scissors";
}

//destructor deletes the members of the linked list
//checks if room has been visited and deletes the letter if necessary
RPS::~RPS(){
  delete rock;
  delete paper;
  delete scissors;
  if (visited == false){
    delete letter;
  }
}

//event gets the player's selection compares it to the computer's selection,
//prints the winner, and adds the letter to the player's items stack when
//they win.
bool RPS::event(std::stack<Items*> & playerItems){
  if (visited == false){
    int userSelection;
    int compSelection = ((rand() % 3)+1);
    std::cout << "..............................." << '\n'
              << "Win at rock - paper - siscors to pass this room:" << '\n'
              << "Select from the following" << '\n'
              << "1. rock" << '\n'
              << "2. paper" << '\n'
              << "3. scissors" << '\n';
    userSelection = getInt(1,3);
    switch (userSelection) {
      case 1:{
        userThrow = rock;
        break;
        }
      case 2:{
        userThrow = paper;
        break;
        }
      case 3:{
        userThrow = scissors;
      }
      default:
        break;
    }
    switch (compSelection) {
      case 1:{
        compThrow = rock;
        break;
      }
      case 2:{
        compThrow = paper;
        break;
      }
      case 3:{
        compThrow = scissors;
        break;
      }
      default:{
        std::cout << "Shouldn't be here " << compSelection << '\n';
      }
    }

    std::cout << "comp throw = " << compThrow->option << '\n';
    std::cout << "user throw = " << userThrow->option << '\n';

    if (userThrow->beats == compThrow){
      std::cout << "User beats computer" << '\n'
                << "picked up letter " << letter->getItemName() << '\n';
      visited = true;
      playerItems.push(letter);
      letter = nullptr;
      return true;
    }
    else if (userThrow->loses == compThrow){
      std::cout << "User loses to computer" << '\n'
                << "Come back to try again." << '\n';
      return false;
    }
    else{
      std::cout << "Its a draw" << '\n'
                << "Come back to try again." << '\n';
      return false;
    }
  }
  else{
    return true;
  }
}
