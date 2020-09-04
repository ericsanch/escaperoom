#First test makefile

#Variables to control Makefile operation
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

#targets
main: main.o escapeRoom.o validateInput.o Space.o Hallway.o ExitRoom.o RollDice.o DarkRoom.o FlashlightRoom.o TriviaRoom.o RPS.o Items.o Flashlight.o Letters.o player.o Map.o
	$(CXX) $(CXXFLAGS) -o main main.o escapeRoom.o validateInput.o Space.o Hallway.o ExitRoom.o RollDice.o DarkRoom.o FlashlightRoom.o TriviaRoom.o RPS.o Items.o Flashlight.o Letters.o player.o Map.o

main.o: escapeRoom.o validateInput.o Space.o Hallway.o ExitRoom.o RollDice.o DarkRoom.o FlashlightRoom.o TriviaRoom.o RPS.o Items.o Flashlight.o Letters.o player.o Map.o

escapeRoom.o: escapeRoom.hpp

Space.o: Space.hpp

Hallway.o: Hallway.hpp

ExitRoom.o: ExitRoom.hpp

RollDice.o: RollDice.hpp

DarkRoom.o: DarkRoom.hpp

FlashlightRoom.o: FlashlightRoom.hpp

TriviaRoom.o: TriviaRoom.hpp

RPS.o: RPS.hpp

Items.o: Items.hpp

Flashlight.o: Flashlight.hpp

player.o: player.hpp

Map.o: Map.hpp

validateInput.o: validateInput.hpp

.PHONY : clean
clean:
	-rm *.o main 
