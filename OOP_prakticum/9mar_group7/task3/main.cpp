#include <iostream>
#include "University.hpp"
#include "Student.hpp"

int main()
{
    University SU;
    SU.readNewSpecialty();
    SU.readNewSpecialty();
    SU.readNewSpecialty();
    SU.printStructure();
    SU.readNewSubject();
    std::cin.ignore();
    SU.readNewSubject();
    std::cin.ignore();
    SU.readNewSubject();
    std::cin.ignore();
    SU.readNewSubject();
    std::cin.ignore();
    SU.readNewSubject();
    std::cin.ignore();
    Student s[5];
    for (unsigned i = 0; i < 5; ++i)
    {
        s[i].read(SU);
        std::cin.ignore();
    }

    SU.printStructure();
    SU.printStudents();
    return 0;
}