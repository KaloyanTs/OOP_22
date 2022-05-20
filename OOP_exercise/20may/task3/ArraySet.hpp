#ifndef __ARRAY_SET_HPP
#define __ARRAY_SET_HPP
#include "IntSet.hpp"
#include <cassert>

class ArraySet : public IntSet
{
    int *set;
    const size_t capacity;
    size_t size;

public:
    ArraySet(int size = 0);
    IntSet *clone() const { return new ArraySet(*this); }
    bool member(int x) const;
    int get(int i) const;
    bool operator<(const IntSet &other) const;
    bool operator*(const IntSet &other) const;

    bool insert(int x);
    bool remove(int x);
};

#endif