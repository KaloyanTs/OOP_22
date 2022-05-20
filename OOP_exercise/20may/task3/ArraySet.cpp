#include "ArraySet.hpp"

ArraySet::ArraySet(int _capacity)
    : capacity(_capacity), size(0), set(nullptr)
{
    if (capacity)
        set = new int[capacity];
}

bool ArraySet::member(int x) const
{
    unsigned i = 0;
    while (i < size && x != set[i])
        ++i;
    return i < size;
}

int ArraySet::get(int i) const
{
    assert(i < size);
    return set[i];
}

bool ArraySet::operator<(const IntSet &other) const
{
    unsigned i = 0;
    while (i < size && other.member(set[i]))
        ++i;
    return i >= size;
}

bool ArraySet::operator*(const IntSet &other) const
{
    unsigned i = 0;
    while (i < size && !other.member(set[i]))
        ++i;
    return i < size;
}

bool ArraySet::insert(int x)
{
    return size < capacity && (set[size++] = x, true);
}

bool ArraySet::remove(int x)
{
    unsigned i = 0;
    while (i < size && x != set[i])
        ++i;
    if (i >= size)
        return false;
    --size;
    while (i < size)
    {
        set[i] = set[i + 1];
        ++i;
    }
    return true;
}
