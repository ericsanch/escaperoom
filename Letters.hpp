//  finalProject - Escape Room
//  Letters.hpp
//  Eric Sanchez
//  12/10/19
//
//  This file contains the class definition for the letters object.
//  The letters object is a derived class of the items class. It
//  stores the letter as a character and has a constructor which
//  accepts the letter being stored by the object as a string
//

#ifndef Letters_hpp
#define Letters_hpp

#include <iostream>
#include "Items.hpp"

class Letters : public Items{
  public:
    Letters(std::string);
    ~Letters();
};

#endif /* Letters_hpp */
