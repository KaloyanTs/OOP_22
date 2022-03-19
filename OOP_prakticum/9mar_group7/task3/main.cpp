#include <iostream>
#include "Specialty.hpp"

int main()
{
    Specialty **SU;
    SU = new Specialty *[3];
    SU[0] = new Specialty("Computer science");
    SU[1] = new Specialty("Informatics");
    SU[2] = new Specialty("Software engeneering");
    Student s[5];
    for (unsigned i = 0; i < 5; ++i)
    {
        s[i].read(SU, 3);
        std::cin.ignore();
    }
    for (unsigned i = 0; i < 3; ++i)
        SU[i]->print();
    for (unsigned i = 0; i < 3; ++i)
        delete SU[i];
    delete[] SU;
    return 0;
}