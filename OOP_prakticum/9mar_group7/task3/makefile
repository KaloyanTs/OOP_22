main: main.o Subject.o Student.o University.o Specialty.o
	g++ -o uni.exe main.o Subject.o Student.o University.o Specialty.o
main.o: main.cpp Subject.o Student.o University.o Specialty.o Classes.hpp
	g++ -g -c main.cpp
Subject.o: Subject.hpp Subject.cpp Specialty.o Classes.hpp
	g++ -g -c Subject.cpp
Specialty.o: Specialty.hpp Specialty.cpp Student.o Classes.hpp
	g++ -g -c Specialty.cpp
Student.o: Student.hpp Student.cpp Specialty.o Classes.hpp
	g++ -g -c Student.cpp
University.o: University.hpp University.cpp Student.o Specialty.o Subject.o Classes.hpp
	g++ -g -c University.cpp
clean:
	del *.o *.exe