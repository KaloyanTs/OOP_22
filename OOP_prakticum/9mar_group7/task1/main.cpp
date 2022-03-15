#include <iostream>
#include "University.hpp"

int main()
{
    University SU;
    Scientist a;
    a.read();
    std::cin.ignore();
    SU.hireScientist(a);
    a.read();
    std::cin.ignore();
    SU.hireScientist(a);
    a.read();
    std::cin.ignore();
    SU.hireScientist(a);
    a.read();
    std::cin.ignore();
    SU.hireScientist(a);
    SU.print();
    SU.fireScientist("minko");
    SU.elevateScientist("me");
    SU.fireScientists(a.getTitle());
    SU.print();
    return 0;
}