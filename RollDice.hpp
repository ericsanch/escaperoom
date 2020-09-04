//  finalProject - Escape Room
//  RollDice.hpp
//  Eric Sanchez
//  12/10/19
//
//  This file contains the class definition for the Roll Dice space.
//  This room uses the letter member of the base class. It includes a
//  constructor and an event function
//

#ifndef RollDice_hpp
#define RollDice_hpp

#include <iostream>
#include <limits>
#include "Space.hpp"
#include "Items.hpp"
#include "Letters.hpp"

class RollDice : public Space{
  public:
    RollDice(std::string);
    ~RollDice();
    bool event(std::stack<Items*>&);
};

#endif /* RollDice_hpp */
