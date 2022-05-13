#include "Person.hpp"

Person::Person(const char *_name, unsigned _age)
    : name(new char[strlen(_name) + 1]), age(_age)
{
    strcpy(name, _name);
}

void Person::clear()
{
    delete[] name;
}

void Person::copy(const Person &other)
{
    clear();
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    age = other.age;
}

Person::Person(const Person &other)
    : name(nullptr)
{
    copy(other);
}

Person &Person::operator=(const Person &other)
{
    if (this != &other)
        copy(other);
    return *this;
}

Person::~Person()
{
    clear();
}

std::ostream &operator<<(std::ostream &os, const Person &P)
{
    P.print(os);
    return os;
}

void Person::print(std::ostream &os) const
{
    os << "Name: " << name << "\tAge: " << age;
}
