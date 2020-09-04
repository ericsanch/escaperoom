//  finalProject - Escape Room
//  Map.cpp
//  Eric Sanchez
//  12/10/19
//
//  This file contains the function definitions used by the Map class.
//  Functions included are a constructor to make the map using the space
//  types, items they contain, getting the type of adjacent spaces, 
//  moving the player, and printing the map
//

#include "Map.hpp"

//Map constructor, takes no arguments, sets the position of each node
//within the printing of the map, the room types, and creates the objects
//that each room contains
Map::Map(){
  topMid = new MapNode(12, 2, "top mid", new RPS("c"));
  topLeft = new MapNode(4, 2, "top left", new TriviaRoom("p", "earthTrivia.txt"));
  topRight = new MapNode(20, 2, "top right", new DarkRoom("e"));
  midLeft = new MapNode(4, 6, "mid left", new Hallway());
  midMid = new MapNode(12, 6, "mid mid", new Hallway());
  midRight = new MapNode(20, 6, "mid right", new Hallway());
  botLeft = new MapNode(4, 10, "bottom left", new FlashlightRoom());
  botMid = new MapNode(12, 10, "bottom mid", new TriviaRoom("e", "spaceTrivia.txt"));
  botRight = new MapNode(20, 10, "bottom right", new RollDice("a"));
  exit = new MapNode(25, 6, "exit", new ExitRoom());
  
//associate each node on the map 
  topLeft->right = topMid;
  topLeft->up = nullptr;
  topLeft->left = nullptr;
  topLeft->down = midLeft;
  
  topMid->left = topLeft;
  topMid->up = nullptr;
  topMid->right = nullptr;
  topMid->down = midMid;
  
  topRight->left = nullptr;
  topRight->up = nullptr;
  topRight->down = midRight;
  topRight->right = nullptr;
  
  midLeft->left = nullptr;
  midLeft->right = midMid;
  midLeft->up = topLeft;
  midLeft->down = botLeft;
  
  midMid->left = midLeft;
  midMid->right = midRight;
  midMid->up = topMid;
  midMid->down = botMid;
  
  midRight->left = midMid;
  midRight->right = exit;
  midRight->down = botRight;
  midRight->up = topRight;
  
  botLeft->left = nullptr;
  botLeft->right = nullptr;
  botLeft->up = midLeft;
  botLeft->down = nullptr;
  
  botMid->left = nullptr;
  botMid->right = botRight;
  botMid->up = midMid;
  botMid->down = nullptr;
  
  botRight->left = botMid;
  botRight->right = nullptr;
  botRight->down = nullptr;
  botRight->up = midRight;
 
  //player is identified as curr in the map class. Initialized to the
  //middle, row, left column 
  curr = midLeft;

}

//Map destructor, deletes each node used by the game
Map::~Map(){
  delete topLeft;
  delete topMid;
  delete topRight;
  delete midLeft;
  delete midMid;
  delete midRight;
  delete botLeft;
  delete botMid;
  delete botRight;
//  delete curr;
  delete exit;
}

void Map::printRight(){
  if (curr->right == nullptr){
    std::cout << "boundary to the right" << '\n';
  }
  else{
    std::cout << curr->x;
    std::cout << curr->right->roomName << ", " << curr->right->x << ", " << curr->right->y << '\n';
  }
}

//function to print the map
void Map::printMap(){

  MAP.open(MAP_FILE);
  std::string contents;
  
  int lineCount = 0;
  char cur = '\0';
  int chars = 0;
  
  int x = curr->x;
  int y = curr->y;
  
//check for positions of each room and the player's location, print + if it 
//is a non-completed room, print X to represent the player, otherwise print
//a blank space
  while (MAP.get(cur)){
    if ((!topLeft->roomType->getVisited() && lineCount == topLeft->y && chars == topLeft->x) ||
        (!topMid->roomType->getVisited() && lineCount == topMid->y && chars == topMid->x) ||
        (!topRight->roomType->getVisited() && lineCount == topRight->y && chars == topRight->x) ||
        (!botLeft->roomType->getVisited() && lineCount == botLeft->y && chars == botLeft->x) ||
        (!botMid->roomType->getVisited() && lineCount == botMid->y && chars == botMid->x) ||
        (!botRight->roomType->getVisited() && lineCount == botRight->y && chars == botRight->x)){
      std::cout << '+';
      chars++;
    }
    else{
      if (lineCount == y && chars == x){
        std::cout << 'X';
        chars++;
      }
      else{
        if (cur == '\n'){
          std::cout << cur;
          lineCount++;
          chars = 0;
        }
        else{
          chars++;
          std::cout << cur;
        }
      }
    }
  }
  MAP.close();
}

//moveRight takes the player's items stack as a parameter and
//returns a bool
bool Map::moveRight(std::stack<Items*> & playerItems){
  if (curr->right->roomType->event(playerItems)){
    curr = curr->right;
    return true;
  }
  else{
    return false;
  }
}
//moveLeft takes the player's items stack as a parameter and
//returns a bool
bool Map::moveLeft(std::stack<Items*> & playerItems){
  if (curr->left->roomType->event(playerItems)){
    curr = curr->left;
    return true;
  }
  else{ 
    return false;
  }
}
//moveUp takes the player's items stack as a parameter and
//returns a bool
bool Map::moveUp(std::stack<Items*> & playerItems){
  if (curr->up->roomType->event(playerItems)){
    curr = curr->up;
    return true;
  }
  else{
    return false;
  }
}

//moveDown takes the player's items stack as a parameter and
//returns a bool
bool Map::moveDown(std::stack<Items*> & playerItems){
  if (curr->down->roomType->event(playerItems)){
    curr = curr->down;
    return true;
  }
  else{
    return false;
  }
}

//Returns whether the player is on the exit space to determine if the game has been won
bool Map::getExited(){
  return (curr == exit);
}

//returns a bool to determine if the player is trying to move through a wall
bool Map::getUp(){
  if (curr->up == nullptr){
    return false;
  }
  else{
    return true;
  }
}

//returns a bool to determine if the player is trying to move through a wall
bool Map::getDown(){
  if (curr->down == nullptr){
    return false;
  }
  else{
    return true;
  }
}

//returns a bool to determine if the player is trying to move through a wall
bool Map::getLeft(){
  if (curr->left == nullptr){
    return false;
  }
  else{
    return true;
  }
}

//returns a bool to determine if the player is trying to move through a wall
bool Map::getRight(){
  if (curr->right == nullptr){
    return false;
  }
  else{
    return true;
  }
}
