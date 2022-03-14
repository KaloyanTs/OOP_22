#ifndef __VECTOR_HPP
#define __VECTOR_HPP
#include <iostream>
#include <cassert>
const size_t STEP_CAPACITY = 4;

class Vector
{
    int *arr;
    size_t size;
    size_t capacity;
    void copy(const Vector &V);
    void dealloc(int *&array);
    bool enlarge();

public:
    Vector();
    Vector(size_t _capacity);
    Vector(const Vector &V);
    const Vector &operator=(const Vector &V);
    void print() const;
    size_t getSize() const { return size; }
    size_t getCapacity() const { return capacity; }
    int &at(unsigned index) const;
    bool pushBack(int element);
    bool erase(unsigned index);
    bool reserve(unsigned newCapacity);
    ~Vector();
};

#endif