main: main.o NightClub.o
	g++ -o fun.exe main.o NightClub.o Balloon.o Shisha.o Alcohol.o
main.o: main.cpp NightClub.o
	g++ -g -c main.cpp
NightClub.o: Balloon.o Shisha.o Alcohol.o
	g++ -g -c NightClub.cpp
Balloon.o: Balloon.hpp Balloon.cpp
	g++ -g -c Balloon.cpp
Shisha.o: Shisha.hpp Shisha.cpp
	g++ -g -c Shisha.cpp 
Alcohol.o: Alcohol.hpp Alcohol.cpp
	g++ -g -c Alcohol.cpp
clean: 
	del *.o *.exe