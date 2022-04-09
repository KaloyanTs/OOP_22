#include <iostream>
#include "Animal.hpp"

int main()
{
    Animal dog("Josh", "Best breed", "Me", 5);
    dog.writeBinary("binary.dat");
    dog.writeText("text.txt");
    return 0;
}