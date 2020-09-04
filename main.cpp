//  finalProject - Escape Room
//  main.cpp
//  Eric Sanchez
//  12/10/19
//
//  This file contains the main function to run the program. The main
//  function simply creates a new Escape object and runs the startSequence
//  for the object. From there, the Escape object takes over for the 
//  remainder of the program.
//

#include <iostream>
#include <fstream>
#include <string>
#include "escapeRoom.hpp"
#include "Map.hpp"

int main(){
  //create Escape object and run startSequence()
  Escape newEscape;
  newEscape.startSequence();
  return 0;
}

