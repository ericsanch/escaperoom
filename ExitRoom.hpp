//  finalProject - Escape Room
//  ExitRoom.hpp
//  Eric Sanchez
//  12/10/19
//
//  This file contains the Exit Room class definition. This is a derived
//  class of the Space type. it contains a temp stack for checking the
//  contents of the player's item stack, an integer for keeping track
//  of the number of items the user has, a constructor, and an event function
//

#ifndef ExitRoom_hpp
#define ExitRoom_hpp

#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
//#include <functional>
#include "Space.hpp"
#include "Items.hpp"

class ExitRoom : public Space{

  private:
    std::stack<Items*> tempItems;
    int itemCount = 0;

  public:
    ExitRoom();
    bool event(std::stack<Items*>&);
};

#endif /* ExitRoom_hpp */
