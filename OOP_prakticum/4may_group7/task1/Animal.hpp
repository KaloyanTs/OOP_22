#ifndef __ANIMAL_HPP
#define __ANIMAL_HPP
#include <iostream>
#include <cstring>

class Animal
{
    char *name;
    unsigned age;
    void clear() { delete[] name; }

protected:
    void copy(const Animal &other);

public:
    Animal(const char *_name = "unknown", unsigned _age = 0);
    Animal(const Animal &other);
    Animal &operator=(const Animal &other);
    virtual ~Animal();

    const char *getName() const { return name; }
    unsigned getAge() const { return age; }

    void setName(const char *_name);
};

std::ostream &operator<<(std::ostream &os, const Animal &A);

#endif