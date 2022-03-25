#include "Corporation.hpp"

void Corporation::copy(const Corporation &C)
{
    delete[] name;
    name = new char[strlen(C.name) + 1];
    assert(name);
    strcpy(name, C.name);
    employees = C.employees;
    mother = C.mother;
    delete[] daughters;
    daughterCapacity = C.daughterCapacity;
    daughterCount = C.daughterCount;
    daughters = new const Corporation *[C.daughterCapacity];
    assert(daughters);
    for (unsigned i = 0; i < daughterCount; ++i)
        daughters[i] = C.daughters[i];
}

Corporation::Corporation(const char *_name, size_t Employeecount, size_t DaughterCap)
    : name(new char[strlen(_name) + 1]),
      employees(Employeecount),
      mother(nullptr),
      daughters(new const Corporation *[DaughterCap]),
      daughterCapacity(DaughterCap),
      daughterCount(0)
{
    assert(name && daughters);
    strcpy(name, _name);
}

void Corporation::print() const
{
    std::cout << "Name: " << (name ? name : " - ")
              << "\nMother: " << (mother ? mother->getName() : " - ")
              << "Daughters:\n";
    for (unsigned i = 0; i < daughterCount; ++i)
    {
        std::cout << '\t' << i + 1 << ": "
                  << daughters[i]->getName() << '\n';
    }
    std::cout << "Employees:\n";
    employees.print();
}

const Corporation &Corporation::acquire(Corporation &C)
{
    employees += C.employees;
    C.mother = this;
    for (unsigned i = 0; i < C.daughterCount; ++i)
    {
        if (daughterCapacity == daughterCount)
            resizeDaughters(daughterCapacity * 2 + 1);
        daughters[daughterCount++] = C.daughters[i];
    }
    if (daughterCapacity == daughterCount)
        resizeDaughters(daughterCapacity * 2 + 1);
    daughters[daughterCount++] = &C;
    delete[] C.daughters;
    C.daughters = nullptr;
    C.daughterCapacity = C.daughterCount = 0;
    return *this;
}

Corporation::~Corporation()
{
    delete[] daughters;
    delete[] name;
}

void Corporation::resizeDaughters(size_t newCap)
{
    assert(newCap > daughterCapacity);
    daughterCapacity = newCap;
    const Corporation **newDaughters = new const Corporation *[daughterCapacity];
    for (unsigned i = 0; i < daughterCount; ++i)
        newDaughters[i] = daughters[i];
    delete[] daughters;
    daughters = newDaughters;
}

Corporation &Corporation::hire(const Employee &E)
{
    employees.addEmployee(E);
    return *this;
}
