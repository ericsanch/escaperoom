//  finalProject - Escape Room
//  Map.hpp
//  Eric Sanchez
//  12/10/19
//
//  This file contains the Map class declaration used by the program.
//  The map class has a data structure which contains the 4 directions
//  the player can move, functions for checking the adjacent spaces, 
//  moving in each direction, and printing the current state of the map.
//

#ifndef Map_hpp
#define Map_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include "Space.hpp"
#include "RPS.hpp"
#include "FlashlightRoom.hpp"
#include "DarkRoom.hpp"
#include "TriviaRoom.hpp"
#include "ExitRoom.hpp"
#include "RollDice.hpp"
#include "validateInput.hpp"
#include "Items.hpp"
#include "Flashlight.hpp"
#include "Hallway.hpp"

class Map{
  protected:
    //data structure for the map spaces
    struct MapNode{
      int x;
      int y;
      Space * roomType;
      std::string roomName;
      MapNode * up;
      MapNode * down;
      MapNode * left;
      MapNode * right;
      MapNode(int x1, int y1, std::string rName, Space * room, Items * item = nullptr){
        x = x1;
        y = y1;
        roomName = rName;
        roomType = room;
      }
      ~MapNode(){
        delete roomType;
      }
    };

    //map node pointers
    MapNode * topLeft;
    MapNode * topMid;
    MapNode * topRight;
    MapNode * midLeft;
    MapNode * midMid;
    MapNode * midRight;
    MapNode * botLeft;
    MapNode * botMid;
    MapNode * botRight;
    MapNode * exit;
    MapNode * curr;

    //variables used for the filestream to print the map
    const std::string MAP_FILE = "map.txt";
    std::ifstream MAP;

    //variables used for checking items and tracking the moved condition
    Items * tempItem;
    bool moved;
  
  public:
    Map();
    ~Map();
    bool getExited();
    bool getUp();
    bool getDown();
    bool getLeft();
    bool getRight();
    bool moveRight(std::stack<Items*>&);
    bool moveLeft(std::stack<Items*>&);
    bool moveUp(std::stack<Items*>&);
    bool moveDown(std::stack<Items*>&);
    void printMap();
    void printRight();
};

#endif /* Map_hpp */
