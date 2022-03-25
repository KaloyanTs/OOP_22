#include "Employee.hpp"

Employee::Employee() : name(nullptr), position(nullptr), ID(nullptr), salary(0)
{
}

Employee::Employee(const char *_n, const char *_id, const char *_p, unsigned _s) : salary(_s)
{
    name = new char[strlen(_n) + 1];
    assert(name);
    strcpy(name, _n);
    ID = new char[strlen(_id) + 1];
    assert(ID);
    strcpy(ID, _id);
    position = new char[strlen(_p) + 1];
    assert(position);
    strcpy(position, _p);
}

Employee::Employee(const Employee &E) : name(nullptr), position(nullptr), ID(nullptr), salary(E.salary)
{
    copy(E);
}

void Employee::print() const
{
    std::cout << "Name: " << name << "\tID: " << ID
              << "\tPosition: " << position
              << "\tSalary: " << salary << '\n';
}

Employee::~Employee()
{
    delete[] name;
    delete[] ID;
    delete[] position;
}

void Employee::copy(const Employee &E)
{
    delete[] name;
    delete[] position;
    delete[] ID;
    name = new char[strlen(E.name) + 1];
    assert(name);
    strcpy(name, E.name);
    position = new char[strlen(E.position) + 1];
    assert(position);
    strcpy(position, E.position);
    ID = new char[strlen(E.ID) + 1];
    assert(ID);
    strcpy(ID, E.ID);
}

void Employee::setPosition(const char *_p)
{
    delete[] position;
    position = new char[strlen(_p) + 1];
    assert(position);
    strcpy(position, _p);
}

const Employee &Employee::operator=(const Employee &C)
{
    if (this != &C)
        copy(C);
    return *this;
}
