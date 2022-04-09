#ifndef __ANIMAL_HPP
#define __ANIMAL_HPP
#include <iostream>
#include <cstring>
#include <cassert>
#include <fstream>

class Animal
{
    char *name;
    char *breed;
    char *owner;
    unsigned age;
    void copy(const Animal &other);
    void clear();

public:
    Animal();
    Animal(const char *_n, const char *_b, const char *_o, unsigned _age);
    Animal(const Animal &other);
    ~Animal();
    Animal &operator=(const Animal &other);
    friend std::ostream &operator<<(std::ostream &os, const Animal &A);
    friend std::istream &operator>>(std::istream &os, Animal &A);
    void writeBinary(const char *path) const;
    void writeText(const char *path) const;
};

#endif