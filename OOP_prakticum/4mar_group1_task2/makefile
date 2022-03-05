main: main.o Sector.o Company.o
	g++ -o main.exe main.o Sector.o Company.o
main.o: main.cpp Sector.o
	g++ -g -c main.cpp
Sector.o: Sector.hpp Sector.cpp Company.o
	g++ -g -c Sector.cpp
Company.o: Company.cpp Company.hpp 
	g++ -g -c Company.cpp
clean:
	del *.o main.exe