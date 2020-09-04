//  finalProject - Escape Room
//  Hallway.cpp
//  Eric Sanchez
//  12/10/19
//
//  This file contains the event() function declaration for the hallway space
//  This function doesn't really do much but it returns true for the calling
//  function to know that the player has moved.
//

#include "Hallway.hpp"

Hallway::Hallway(){

}

bool Hallway::event(std::stack<Items*> & playerItems){
  return true;
}
