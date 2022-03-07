main: main.o Beer.o
	g++ -o main.exe main.o Beer.o
main.o: main.cpp Beer.o
	g++ -g -c main.cpp
Beer.o: Beer.hpp Beer.cpp
	g++ -g -c Beer.cpp
clean:
	del *.o *.exe