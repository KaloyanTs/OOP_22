#include <iostream>
#include "Beer.hpp"

int main()
{
    Beer a("Becks", 500);
    Beer b("Staropramen", 250);
    a.print();
    b.print();
    a.add(b);
    a.print();
    std::cout << std::boolalpha << a.contains(b.getBrand()) << '\n';
    return 0;
}