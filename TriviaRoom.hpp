//  finalProject - Escape Room
//  TriviaRoom.hpp
//  Eric Sanchez
//  12/10/19
//
//  This file contains the Trivia Room class definition, derived from
//  the Space class. It includes variables to store the user's response
//  to the question, a filename and filestream for reading the files
//  that store the trivia questions, a constructor, readFile() function,
//  and event() function.
//

#ifndef TriviaRoom_hpp
#define TriviaRoom_hpp

#include <iostream>
#include <stack>
#include <fstream>
#include <cctype>
#include <algorithm>
#include "Space.hpp"
#include "Items.hpp"
#include "Letters.hpp"

class TriviaRoom : public Space{
  private:
    std::string filename;
    std::string response;
    std::string answer;
    std::ifstream IFS;
  public:
    TriviaRoom(std::string, std::string);
    ~TriviaRoom();
    bool event(std::stack<Items*>&);
    std::string readFile(int start);
};

#endif /* TriviaRoom_hpp */
