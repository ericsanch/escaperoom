//  finalProject - Escape Room
//  escapeRoom.hpp
//  Eric Sanchez
//  12/10/19
//
//  This file contains the class definition for the escape room object.
//  The class has an unsigned int as a data member for seeding the random
//  number generator. It has two functions for executing the start sequence
//  menu or playing the game. Since the class object will only have one
//  instance and doesn't require any additional input for starting, the
//  default constructor is used.
//

#ifndef escapeRoom_hpp
#define escapeRoom_hpp

#include <iostream>
#include <fstream>
#include <cstdlib>

class Escape{
  private:
    unsigned seed;
    char waitChar;
  public:
    void startSequence();
    void playGame();
};

#endif /* escapeRoom_hpp */
