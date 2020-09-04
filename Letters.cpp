//  finalProject - Escape Room
//  Letters.cpp
//  Eric Sanchez
//  12/10/19
//
//  This file contains the function definition for the letters constructor
//

#include "Letters.hpp"

//takes the letter being stored as a string parameter and sets the
//item name to the letter passed to it.
Letters::Letters(std::string letter){
  itemName = letter;
}

Letters::~Letters(){};
