main: main.o Corporation.o Employee.o EmployeeVector.o
	g++ -o corp.exe main.o Corporation.o Employee.o EmployeeVector.o
main.o: main.cpp Corporation.o
	g++ -g -c main.cpp
Corporation.o: Corporation.hpp Corporation.cpp EmployeeVector.o
	g++ -g -c Corporation.cpp
EmployeeVector.o: EmployeeVector.hpp EmployeeVector.cpp Employee.o
	g++ -g -c EmployeeVector.cpp
Employee.o: Employee.hpp Employee.cpp
	g++ -g -c Employee.cpp
clean:
	del *.o *.exe