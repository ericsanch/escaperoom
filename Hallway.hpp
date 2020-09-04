//  finalProject - Escape Room
//  Hallway.hpp
//  Eric Sanchez
//  12/10/19
//
//  This file contains the class definition for the Hallway Space
//  The hallway space is effectively an empty space for the user to
//  move through. It contains no items for the user to pick up
//

#ifndef Hallway_hpp
#define Hallway_hpp

#include <iostream>
#include <stack>
#include "Space.hpp"
#include "Items.hpp"

class Hallway : public Space{
  public:
    Hallway();
    bool event(std::stack<Items*>&);
};

#endif /* Hallway_hpp */
