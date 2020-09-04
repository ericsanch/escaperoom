//  finalProject - Escape Room
//  ExitRoom.cpp
//  Eric Sanchez
//  12/10/19
//
//  This file contains the function definitions for the ExitRoom class.
//  The constructor sets the visited variable to false. The event function
//  checks what items are in the player's item stack and either lets the
//  user attempt to answer the exit question, or pushes them back to their
//  previous space.
//

#include "ExitRoom.hpp"

//constructor, sets visited to false
ExitRoom::ExitRoom(){
  visited = false;
}

//event takes the user's items stack as a reference variable.
bool ExitRoom::event(std::stack<Items*> & playerItems){
  itemCount = 0;
  tempItems = playerItems;
  //check for all items in the stack
  while (!tempItems.empty()){
    itemCount++;
    tempItems.pop();
  }
  if (itemCount != 6){
    std::cout << "Find the remaining letters before attempting to exit" << '\n';
    return false;
  }

  //print the instructions and the player's items
  std::string response;
  tempItems = playerItems;
  std::cout << "..............................." << '\n'
            << "You collected the following letters:" << '\n';
  while (!tempItems.empty()){
    tempItem = tempItems.top();
    if (tempItem->getItemName() == "Flashlight"){
      tempItems.pop();
    }
    else{
      std::cout << tempItem->getItemName()<< ", ";
      tempItems.pop();
    }
  }
  std::cout << '\n' << "Rearrange the letters determine the passcode" << '\n'
            << "Enter the passcode to exit and win!" << '\n';
  std::cin >> response;

  //string to lower function reference: https://stackoverflow.com/questions/16792456/no-matching-function-for-call-to-transform
  std::transform(response.begin(), response.end(), response.begin(), [](unsigned char c){ return std::tolower(c); });
  if (response != "peace"){
    std::cout << "incorrect, come back and try again" << '\n';
    return false;
  }
  return true;
}
