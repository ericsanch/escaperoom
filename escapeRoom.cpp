//  finalProject - Escape Room
//  escapeRoom.cpp
//  Eric Sanchez
//  12/10/19
//
//  This file contains the function declarations for the Escape class.
//  The start sequence function prints the menu for the user to decide
//  whether to start the game, see the instructions, or quit the program.
//  The playGame function contains the general game flow by looping
//  getting the selected direction from the user, moving, adjusting the
//  remaining time, checking whether or not the user has won the game,
//  and printing the map.  
//  

#include "escapeRoom.hpp"
#include "player.hpp"
#include "Map.hpp"

//start sequence gets response from user and calls the playGame function
void Escape::startSequence(){
//  char waitChar;
  std::ifstream IFS;
  std::string input;
  bool quitGame = false;
  bool backToMenu = false;
  std::string response;
  while (quitGame != true){
    std::cout << "Welcome to the Escape Room" << '\n'
              << "Please select from the following:" << '\n'
              << "1 : Start" << '\n'
              << "2 : See Instructions" << '\n'
              << "3 : quit" << '\n';
    std::cin >> response;
    backToMenu = false;

//a nested while loop is used to control when to display the menu again
//after printing the instructions or when the user has completed playing
//the game and asking whether to play again.
    while(backToMenu != true){
      while (!(response == "1" || response == "2" || response == "3")){
        std::cout << "Invalid selection, please select 1, 2, or 3" << '\n';
        std::cin >> response;
      }
      
      switch (std::stoi(response)) {
      case 1:{
        std::cout << "Starting Escape Room..." << '\n' << '\n';
        playGame();
        backToMenu = true;
        break;
      }
      case 2:{
        IFS.open("instructions.txt");
        while (!IFS.eof()){
          std::getline(IFS, input);
          std::cout << input << '\n';
        }
        std::cout << "Press enter to return to the main menu..." << '\n';
        std::cin.ignore( 0, '\n' );
        std::cin.get(waitChar);
        std::cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
        backToMenu = true;
        IFS.close();
        break;
      }
      case 3:{
        std::cout << "Thanks for playing." << '\n'
                  << "Exiting Escape Room..." << '\n';
        backToMenu = true;
        quitGame = true;
        break;
      }
      default:
        break;
      }
    }
  }
}

//playGame function controls the flow of the game. Requires no parameters
void Escape::playGame(){
  //seed random number generator
  seed = static_cast<unsigned>(time(0));
  srand(seed);

  //time control
  int timeRemaining = 30;
  int timeChange;

  //create player and map objects
  Player newPlayer;
  Map newMap;
  newMap.printMap();
  std::cout << '\n';

  //continue game until the player runs out of time
  while (timeRemaining > 0){
    std::cout << "Time remaining: " << timeRemaining << '\n';
    timeChange = newPlayer.move(newMap);
    timeRemaining -= timeChange;

    //check if player has won
    if (newPlayer.getWon()){
      std::cout << "Good Job!! \nYou Won with "
                << timeRemaining << " minutes remaining" << '\n';
      std::cout << "Press enter to return to the main menu..." << '\n';
      std::cin.ignore( 0, '\n' );
      std::cin.get(waitChar);
      std::cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
      break;
    }
    else{
      std::cout << '\n';
      newMap.printMap();
      std::cout << '\n';
    }
  }
  //check for out of time
  if (timeRemaining <= 0){
    std::cout << "Sorry, you lost. You ran out of time" << '\n';
    std::cout << "Press enter to return to the main menu..." << '\n';
    std::cin.ignore( 0, '\n' );
    std::cin.get(waitChar);
    std::cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
  }
}
