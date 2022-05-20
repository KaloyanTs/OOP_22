#include <iostream>
#include "Relation.hpp"

int main()
{
    int a = 2, b = 6, c = 3;
    Relation<int> r1(a, b, "is smaller than"),
        r2(b, c, "is divisible by");
    r1.print();
    std::cout << '\n';
    r2.print();
    std::cout << '\n';
    (r1 * r2).print();

    return 0;
}