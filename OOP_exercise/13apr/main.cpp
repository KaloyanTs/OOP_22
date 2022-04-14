#include <iostream>
#include "GP.hpp"

int main()
{
    GP a;
    Patient p;
    std::cin >> p;
    a += p;
    std::cin >> p;
    a += p;
    std::cin >> p;
    a += p;
    a.writeToBinary("out.gp");
    a.readFromBinary("out.gp");
    a.print();
    return 0;
}