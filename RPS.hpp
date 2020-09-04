//  finalProject - Escape Room
//  RPS.hpp
//  Eric Sanchez
//  12/10/19
//
//  This file contains the class definition for the rock-paper-scissors
//  space. The object includes a circular linked list for the rock-paper-
//  scissors heriarchy, a constructor, destructor, and the event function
//

#ifndef RPS_hpp
#define RPS_hpp

#include <iostream>
#include <stack>
#include "Items.hpp"
#include "Letters.hpp"
#include "Space.hpp"

class RPS : public Space{
  private:
    struct RPSOptions{
      RPSOptions * beats;
      RPSOptions * loses;
      std::string option;
      RPSOptions(){
        beats = nullptr;
        loses = nullptr;
      }
    };
  
    RPSOptions * userThrow;
    RPSOptions * compThrow;

    RPSOptions * rock;
    RPSOptions * paper;
    RPSOptions * scissors;
  
  public:
    RPS(std::string);
    ~RPS();
    bool event(std::stack<Items*>&);
};

#endif /* RPS_hpp */
