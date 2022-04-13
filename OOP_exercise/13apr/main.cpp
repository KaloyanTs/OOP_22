#include <iostream>
#include "GP.hpp"

int main()
{
    GP a;
    a.readFromBinary("..\\out.gp");
    a.print();
    return 0;
}