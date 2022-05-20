#include "IntRange.hpp"

IntRange::IntRange(int _left, int _right)
    : left(_left), right(_right)
{
    if (left > right)
    {
        left = 1;
        right = 0;
    }
}

bool IntRange::member(int x) const
{
    return x >= left && x <= right;
}

int IntRange::get(int i) const
{
    int res = left + i;
    assert(res <= right);
    return res;
}

bool IntRange::operator<(const IntSet &other) const
{
    unsigned i = left;
    while (i <= right && other.member(i))
        ++i;
    return left <= right && i > right;
}

bool IntRange::operator*(const IntSet &other) const
{
    unsigned i = left;
    while (i <= right && !other.member(i))
        ++i;
    return left <= right && i <= right;
}
