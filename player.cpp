//  finalProject - Escape Room
//  player.cpp
//  Eric Sanchez
//  12/10/19
//
//  This file contains the function declarations for use by the player object
//  These functions include a constructor, destructor which performs garbage
//  collection, moving the player, and returning their won state
//

#include "player.hpp"

//constructor, sets won to false
Player::Player(){
  won = false;
}

//destructor, deletes each item in the items stack
Player::~Player(){
  while (!playerItems.empty()){
    tempItem = playerItems.top();
    delete tempItem;
    playerItems.pop();
  }
}

//move() takes the gameMap object as an argument by reference so that
//gameMap->curr can be updated. Checking for a wall is performed here
//returns the amount of time to be subtracted from the time remaining.
int Player::move(Map &gameMap){
  char selection;
  std::cout << "select direction" << '\n';
  while (true) {
    
    std::cin >> selection;
    switch (selection) {

    case 'h':{
      if (!gameMap.getLeft()){
        std::cout << "Can't move left - wall" << '\n';
        return 0;
      }
      gameMap.moveLeft(playerItems);
      return 1;
      break;
      }

    case 'j':{
      if (!gameMap.getDown()){
        std::cout << "Can't move down - wall" << '\n';
        return 0;
      }
      gameMap.moveDown(playerItems);
      return 1;
      break;
    }

    case 'k':{
      if (!gameMap.getUp()){
        std::cout << "Can't move up - wall" << '\n';
        return 0;
      }
      gameMap.moveUp(playerItems);
      return 1;
      break;
    }

    case 'l':{
      if (!gameMap.getRight()){
        std::cout << "Can't move right - wall" << '\n';
        return 0;
      }
      gameMap.moveRight(playerItems);
      if (gameMap.getExited() == true){
        won = true;
        return 0;
      }
      return 1;
      break;
    }
   
//input validation performed in the default case 
    default:
      std::cout << "Invalid Selection, please choose h, j, k, or l" << '\n';
      std::cin.ignore(100, '\n');
      break;
    }
  }
}

//getWon() simply returns the won state to tell the playGame() function
//when to stop the game
bool Player::getWon(){
  return won;
}
