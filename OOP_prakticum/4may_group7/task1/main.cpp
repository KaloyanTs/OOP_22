#include <iostream>
#include "Pet.hpp"
#include "WildAnimal.hpp"

int main()
{
    Pet p("Dog", 10, "Az", 4634392);
    std::cout << p << '\n';
    p.setName("Cat");
    p.setOwner("Ti");
    std::cout << p << '\n';
    p = Pet("dfd", 324, "dsdfs", 234);
    std::cout << p << '\n';
    std::cout << (Animal)p << '\n';

    WildAnimal p2("Dog", 10, ASIA);
    std::cout << p2 << '\n';
    p2.setName("Cat");
    std::cout << p2 << '\n';
    p2 = WildAnimal("dfd", 324, EUROPE);
    std::cout << p2 << '\n';
    std::cout << (Animal)p2 << '\n';

    Animal *ptr = new WildAnimal("dsff", 89, EUROPE);
    delete ptr;
    return 0;
}