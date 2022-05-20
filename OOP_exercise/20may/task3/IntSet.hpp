#ifndef __INT_SET_HPP
#define __INT_SET_HPP
#include <iostream>

class IntSet
{
public:
    virtual ~IntSet() {}
    virtual IntSet *clone() const = 0;
    virtual bool member(int x) const = 0;
    virtual int get(int i) const = 0;
    virtual bool operator<(const IntSet &other) const = 0;
    virtual bool operator*(const IntSet &other) const = 0;
};

#endif