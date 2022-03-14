main: main.o Vector.o
	g++ -o vector.exe main.o Vector.o
mian.o: main.cpp Vector.o
	g++ -g -c main.cpp
Vector.o: Vector.hpp Vector.cpp
	g++ -g -c Vector.cpp
clean:
	del *.o *.exe