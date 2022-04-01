main: main.o BankAccount.o Bank.o
	g++ -o Bank.exe main.o BankAccount.o Bank.o
main.o: main.cpp Bank.o
	g++ -g -c main.cpp
BankAccount.o: BankAccount.hpp BankAccount.cpp
	g++ -g -c BankAccount.cpp
Bank.o: Bank.hpp Bank.cpp BankAccount.o
	g++ -g -c Bank.cpp
clean:
	del *.o *.exe