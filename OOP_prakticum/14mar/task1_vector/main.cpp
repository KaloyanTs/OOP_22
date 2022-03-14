#include <iostream>
#include "Vector.hpp"

int main()
{
    Vector v;
    v.pushBack(2);
    v.pushBack(3);
    v.pushBack(5);
    v.pushBack(4);
    v.pushBack(9);
    v.pushBack(7);
    v.print();
    std::cout << v.at(1) << '\n';
    v.erase(2);
    v.print();
    return 0;
}