//  finalProject - Escape Room
//  DarkRoom.hpp
//  Eric Sanchez
//  12/10/19
//
//  This file contains the class definition for the DarkRoom space
//  It has a letter object and a item pointer for checking if the
//  user has a flashlight when they enter the room. The event function
//  takes the user items stack as an argument so that it can add
//  the letter to the stack when the room is successfully completed.
//

#ifndef DarkRoom_hpp
#define DarkRoom_hpp

#include <iostream>
#include "Space.hpp"
#include "Letters.hpp"

class DarkRoom : public Space{
  private:
    std::stack<Items*> tempItems;
  
  public:
    DarkRoom(std::string);
    ~DarkRoom();
    bool event(std::stack<Items*>&);
    
};

#endif /* DarkRoom_hpp */
