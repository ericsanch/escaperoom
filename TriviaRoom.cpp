//  finalProject - Escape Room
//  TriviaRoom.cpp
//  Eric Sanchez
//  12/10/19
//
//  This file contains the function definitions used by the Trivia Room
//  space. It includes a constructor which gets the filename for the file
//  stream, sets visited to false, and creates a letter object.
//
//  The event function prints the question, gets the user's response,
//  checks the user's answer, and adds the letter to their items stack when
//  they complete the room.
//
//  The readFile() function reads the file to print the question and answer
//  choices and assigns the answer for checking the user's response.
//

#include "TriviaRoom.hpp"

//constructor, takes the letter and file name as parameters
TriviaRoom::TriviaRoom(std::string val, std::string filename){
  visited = false;
  letter = new Letters(val);
  this->filename = filename;
}

//Destructor deletes the letter object if the room hasn't been visited
TriviaRoom::~TriviaRoom(){
  if (visited == false){
    delete letter;
  }
}

//event asks the question, calls the readFile function to print
//the question and assign the correct answer.
bool TriviaRoom::event(std::stack<Items*> & playerItems){
  if (visited == false){
    std::cout << "..............................." << '\n'
              << "Trivia Time:" << '\n'
              << "Answer the following question to complete this room... " << '\n';
    int num = ((rand() % (3 - 0 + 1)) * 6);
    answer = readFile(num);
    std::cin >> response;

    //string to lower function reference: https://stackoverflow.com/questions/16792456/no-matching-function-for-call-to-transform
    std::transform(response.begin(), response.end(), response.begin(), [](unsigned char c){ return std::tolower(c); });

    while (!(response == "a" || response == "b" || response == "c" || response == "d")){
      std::cout << "Please select a, b, c, or d" << '\n';
      std::cin >>response;
    }

    if (response == answer){
      std::cout << "Correct! You picked up the letter " << letter->getItemName() << '\n';
      playerItems.push(letter);
      visited = true;
      IFS.close();
      return true;
    }
    else{
      std::cout << "Incorrect, please come back and try again" << '\n';
      IFS.close();
      return false;
    }
  }
  else{
    return true;
  }
}

//readFile prints the question randomly selected by the event() function and 
//assigns returns the correct answer.
std::string TriviaRoom::readFile(int start){
  IFS.open(filename);
  for (int i = 0; i < start; i++){
    IFS.ignore(1000, '\n');
  }
  for (int i = 0; i < 5; i++){
    std::string temp;
    std::getline(IFS,temp);
    std::cout << temp << '\n';
  }
  std::string answer;
  IFS >> answer;
  return answer;
}
