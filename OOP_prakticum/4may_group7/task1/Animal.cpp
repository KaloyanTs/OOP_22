#include "Animal.hpp"

Animal::Animal(const char *_name, unsigned _age)
    : name(new char[strlen(_name) + 1]), age(_age)
{
    strcpy(name, _name);
}

void Animal::copy(const Animal &other)
{
    clear();
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    age = other.age;
}

Animal::Animal(const Animal &other)
    : name(nullptr)
{
    copy(other);
}

Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
        copy(other);
    return *this;
}

Animal::~Animal()
{
    clear();
}

std::ostream &operator<<(std::ostream &os, const Animal &A)
{
    return os << "Name: " << A.getName() << "\tAge: " << A.getAge();
}

void Animal::setName(const char *_name)
{
    delete[] name;
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
}
