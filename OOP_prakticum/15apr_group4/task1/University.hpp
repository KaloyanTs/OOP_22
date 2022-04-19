#ifndef __UNIVERSITY_HPP
#define __UNIVERSITY_HPP
#include "Student.hpp"
#include <cassert>
const size_t INIT_CAPACITY = 4;

class University
{
    Student **students;
    size_t size, capacity;
    void copy(const University &other);
    void resize(unsigned newCap);
    void clear();

public:
    University(size_t cap = INIT_CAPACITY);
    University(const University &other);
    ~University();
    void sort(bool (*cmp)(const Student &, const Student &));
    void filter(bool (*pred)(const Student &));

    University &operator+=(const Student &st);
    University &operator-=(const char *fn);
    Student operator[](unsigned index) const;

    friend std::ofstream &operator<<(std::ofstream &os, const University &U);
    friend std::ifstream &operator>>(std::ifstream &is, University &U);
};

#endif