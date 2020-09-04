//  finalProject - Escape Room
//  Space.hpp
//  Eric Sanchez
//  12/10/19
//
//  This file contains the Space class definition. Space is an abstract
//  type which has an item pointer for storing the letter contained
//  in each room, a visited variable used the getVisited() function when
//  printing the map, a destructor, and a pure virtual function event().
//

#ifndef Space_hpp
#define Space_hpp

#include <iostream>
#include "validateInput.hpp"
#include "Items.hpp"

class Space{
  protected:
    bool visited;
    Items* tempItem;
    Items* letter;
  public:
    virtual ~Space(){};
    virtual bool event(std::stack<Items*>&) = 0;
    bool getVisited();
};

#endif /* Space_hpp */
