//  finalProject - Escape Room
//  player.hpp
//  Eric Sanchez
//  12/10/19
//
//  This file contains the class definition for the player class.
//  The player object has data members for keep track of the player's
//  items stack, a tempItem used by the destructor, a moved state,
//  a won state, and functions to create/destroy a player object,
//  moving the player, and getting their won state
//

#ifndef player_hpp
#define player_hpp

#include <iostream>
#include <stack>
#include "Map.hpp"
#include "Items.hpp"
#include "ExitRoom.hpp"

class Player{
  private:
    std::stack <Items*> playerItems;
    Items* tempItem;
    bool won;
    
  public:
    Player();
    ~Player();
    int move(Map&);
    bool getWon();
};

#endif
