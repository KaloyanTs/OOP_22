#ifndef __UNIVERSITY_HPP
#define __UNIVERSITY_HPP
#include "Student.hpp"
const size_t INIT_CAPACITY = 4;

class University
{
    Student **students;
    size_t size, capacity;
    void copy(const University &other);
    void resize(unsigned newCap);
    void clear();

public:
    University(size_t capacity = INIT_CAPACITY);
    University(const University &other);
    ~University();
    void sort(bool (*cmp)(const Student &, const Student &));

    friend std::ostream &operator<<(std::ostream &os, const University U);
    friend std::istream &operator>>(std::istream &is, University U);
};

#endif