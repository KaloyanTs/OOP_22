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
    a.writeToText("out.txt");
    a.readFromText("out.txt");
    a.print();
    return 0;
}