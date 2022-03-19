#include "University.hpp"

University::University()
{
    specialties = nullptr;
    subjects = nullptr;
    spCount = subCount = 0;
    spCapacity = subCapacity = 0;
    std::cout << "<University created successfully.>\n";
}

void University::copy(const University &U)
{
}

University::University(const University &U)
{
    specialties = nullptr;
    subjects = nullptr;
    spCount = subCount = 0;
    spCapacity = subCapacity = 0;
    copy(U);
    std::cout << "<University created successfully.>\n";
}

const University &University::operator=(const University &U)
{
    if (this != &U)
        copy(U);
    return *this;
}

void University::readNewSpecialty()
{
}

void University::readNewSubject()
{
}

void University::printStudents() const
{
    const Student **bufArr = nullptr;
    size_t bufCount;
    for (unsigned i = 0; i < spCount; ++i)
        specialties[i]->print();
}

void University::printStructure() const
{
    std::cout << "Specialties:\n";
    if (spCount)
        for (unsigned i = 0; i < spCount; ++i)
            std::cout << '\t' << i + 1 << ": " << specialties[i]->getName() << '\n';
    std::cout << "Subjects:\n";
    if (subCount)
        for (unsigned i = 0; i < subCount; ++i)
        {
            std::cout << '\t' << i + 1;
            subjects[i]->print();
        }
}

University::~University()
{
    for (unsigned i = 0; i < spCount; ++i)
        delete[] specialties[i];
    delete[] specialties;
    for (unsigned i = 0; i < spCount; ++i)
        delete[] subjects[i];
    delete[] subjects;
    std::cout << "<University deleted successfully.>\n";
}
