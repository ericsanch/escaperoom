//  finalProject - Escape Room
//  Items.cpp
//  Eric Sanchez
//  12/10/19
//
//  This file contains the getItemName function declaration for the items
//  class. It returns the item name as a string used when printing the
//  item type or checking the contents of the player's item stack.
//

#include "Items.hpp"

//function returns the item name as a string
std::string Items::getItemName(){
  return itemName;
}

Items::~Items(){};
