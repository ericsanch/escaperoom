//  finalProject - Escape Room
//  Flashlight.hpp
//  Eric Sanchez
//  12/10/19
//
//  This file contains the class definition for the flashlight object
//  it inherits the itemName variable from the base item class.
//

#ifndef Flashlight_hpp
#define Flashlight_hpp

#include <iostream>
#include "Items.hpp"

class Flashlight : public Items{
  public:
    Flashlight();
    ~Flashlight();
};

#endif /* Flashlight_hpp */
