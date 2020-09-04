//  final Project Escape Room
//  validateInput.cpp
//  Eric Sanchez
//  12/10/19
//
//  This file contains input validate functions for when the user
//  is prompted for integer input. The user's input is stored as a
//  float in this function for validation and promoted when assigned
//  to an int in driver program.
//
#include <limits>
#include <string>
#include <sstream>
#include "validateInput.hpp"

//Gets input from user and checks that it only contains numbers
float getInt(int min, int max)
{
  float input = 0.0;
  float temp = 0.0;
  bool valid = false;
  while (valid != true)
  {
    std::cin >> temp;
    if (temp > 1000000)
    {
      std::cout << "Please enter a number less than 1000000" << '\n';
      valid = false;
    }
    else if (std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "type char/str not allowed, enter int" << '\n';
      temp = 0.0;
    }
    else if (!std::cin.fail())
    {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      if (std::cin.gcount() > 1)
      {
        std::cout << "type char/str not allowed, enter int" << '\n';
      }
      else if (temp < min || temp > max)
      {
        std::cout << "please enter a number between " << min << " and " << max << '\n';
      }
      else if (!std::cin.fail())
      {
        if (isInt(temp))
        {
          input = temp;
          valid = true;
        }
        else
        {
          std::cout << "please enter an integer" << '\n';
          valid = false;
        }
      }
    }
  }
  return input;
}

//isInt function checks if a number is an integer
bool isInt(float check)
{
  int inputCheck = (check*100);
  if (inputCheck % 100 != 0)
    return false;
  else
    return true;
}
