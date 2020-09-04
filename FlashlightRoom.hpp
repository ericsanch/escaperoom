//  finalProject - EscapeRoom
//  FlashlightRoom.hpp
//  Eric Sanchez
//  12/10/19
//
//  This file contains the class definition for the Flashlight room space.
//  It includes an Items pointer to store the flashlight, a constructor,
//  and an event function.
//

#ifndef FlashlightRoom_hpp
#define FlashlightRoom_hpp

#include <iostream>
#include "Space.hpp"
#include "Items.hpp"
#include "Flashlight.hpp"

class FlashlightRoom : public Space{
  private:
    Items * light;
  
  public:
    FlashlightRoom();
    ~FlashlightRoom();
    bool event(std::stack<Items*>&);
};

#endif /* FlashlightRoom_hpp */
