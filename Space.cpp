//  finalProject - Escape Room
//  Space.cpp
//  Eric Sanchez
//  12/10/19
//
//  This file contains the getVisited function for use by the space class.
//  This funtion returns whether or not the space has alread been visited
//  when the printMap function is checking whether to print a + to represent
//  an non-visited room.
//

#include "Space.hpp"

//get visited returns whether or not the space has been completed
bool Space::getVisited(){
  return visited;
}
