main: main.o Product.o Store.hpp
	g++ -o store.exe main.o Product.o Store.o
main.o: main.cpp Store.o
	g++ -g -c main.cpp
Product.o: Product.hpp Product.cpp
	g++ -g -c Product.cpp
Store.o: Store.hpp Store.cpp Product.o
	g++ -g -c Store.cpp
clean:
	del *.o *.exe