//  finalProject - EscapeRoom
//  FlashlightRoom.cpp
//  Eric Sanchez
//  12/10/19
//
//  This file contains the function definitions for the Flashlight room space.
//  The constructor creates a new Flashlight object and sets visited to false.
//  The event checks whether the user has already been in this room. If the
//  user hasn't already been here, they get the flashlight item added to their
//  items stack.
//

#include "FlashlightRoom.hpp"

//Constructor, make new item, initialize visited.
FlashlightRoom::FlashlightRoom(){
  light = new Flashlight();
  visited = false;
}

//Destructor deletes the flashlight object if the room hasn't been visited
FlashlightRoom::~FlashlightRoom(){
  if (visited == false){
    delete light;
  }
}

//event function pushes the flashlight to the items stack if the user
//hasn't already been in this room.
bool FlashlightRoom::event(std::stack<Items*> & playerItems){
  if (visited == true){
    return true;
  }
  else{
    std::cout << "..............................." << '\n'
              << "You found a flashlight in this room and picked it up!" << '\n'
              << "This might be useful later" << '\n';
    visited = true;
    playerItems.push(light);
    light = nullptr;
    return true;
  }
}
