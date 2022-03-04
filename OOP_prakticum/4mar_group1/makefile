main: main.o Map.o Ship.o Player.o Game.o
	g++ -o main.exe main.o Map.o Ship.o Player.o Game.o -g
main.o: main.cpp Map.hpp Types.hpp Ship.hpp Player.hpp Game.hpp
	g++ -g -c main.cpp
Map.o: Map.hpp Map.cpp Direction.hpp Ship.hpp Ship.cpp Cell.hpp Types.hpp
	g++ -g -c Map.cpp
Ship.o: Ship.cpp Map.hpp Ship.hpp Cell.hpp Direction.hpp Types.hpp
	g++ -g -c Ship.cpp
Player.o: Player.hpp Player.cpp Map.hpp Map.cpp
	g++ -g -c Player.cpp
Game.o: Game.hpp Game.cpp Player.cpp Player.hpp
	g++ -g -c Game.cpp
clean: 
	del *.o main.exe
debug:
	gdb main.exe