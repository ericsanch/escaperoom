//  finalProject - Escape Room
//  Items.hpp
//  Eric Sanchez
//  12/10/19
//
//  This file contains the class definition for the items object.
//  The items object is abstract. It has a data member for keeping
//  track of the type of derived item being created, a default constructor,
//  and a function to get the item name which is used by the event() functions
//

#ifndef Items_hpp
#define Items_hpp

#include <iostream>
#include <stack>
#include "Items.hpp"

class Items{
  protected:
    std::string itemName;
  public:
    Items(){};
    virtual ~Items() = 0;
    std::string getItemName();
};

#endif /* Items_hpp */
