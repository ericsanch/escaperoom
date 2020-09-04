//  finalProject - Escape Room
//  DarkRoom.cpp
//  Eric Sanchez
//  12/10/19
//
//  This file contains the function definitions for the DarkRoom class
//  The constructor takes the letter for the space as an argument to 
//  create a letter object. The events function checks the user's item
//  stack for a flashlight before allowing the user to complete the room
//

#include "DarkRoom.hpp"

//Constructor, visited defaults to false, creates a new letter object
//with the letter passed to it
DarkRoom::DarkRoom(std::string val){
  visited = false;
  letter = new Letters(val);
}

//destructor deletes the letter object if the room hasn't been visited
DarkRoom::~DarkRoom(){
  if (visited == false){
    delete letter;
  }
}

//event() function, overridden from base class. Checks if the room
//has been fisited then executes checking for the flashlight in the
//user's stack and awards the letter based on this result
bool DarkRoom::event(std::stack<Items*> & playerItems){
  if (visited == false){
    tempItems = playerItems;
    while (!tempItems.empty()){
      tempItem = tempItems.top();
      if (tempItem->getItemName() == "Flashlight"){
        std::cout << "You entered a very dark room" << '\n'
                  << "You turned on your flashlight and found the letter " 
                  << letter->getItemName() << '\n';
        visited = true;
        playerItems.push(letter);
        return true;
      }
      tempItems.pop();
    }
      std::cout << "It's dark in here." << '\n'
                << "Find a flashlight so you can see in here" << '\n';
      return false;
  }
  else{
    return true;
  }
  
  return NULL;
}
