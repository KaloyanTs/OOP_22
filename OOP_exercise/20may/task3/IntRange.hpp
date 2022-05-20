#ifndef __INT_RANGE_HPP
#define __INT_RANGE_HPP
#include "IntSet.hpp"
#include <cassert>

class IntRange : public IntSet
{
    int left, right;

public:
    // set from 1 to 0 is the empty set
    IntRange(int _left = 1, int _right = 0);
    IntSet *clone() const { return new IntRange(*this); }
    bool member(int x) const;
    int get(int i) const;
    bool operator<(const IntSet &other) const;
    bool operator*(const IntSet &other) const;
};

#endif