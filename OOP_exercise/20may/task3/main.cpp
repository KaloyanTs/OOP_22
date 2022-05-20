#include <iostream>
#include "IntRange.hpp"
#include "ArraySet.hpp"

bool mon(IntSet *sets[], int n)
{
    --n;
    unsigned i = 0;
    while (i < n && *sets[i] < *sets[i + 1])
        ++i;
    return i >= n;
}

int main()
{
    ArraySet set1(5);
    set1.insert(5);
    set1.insert(6);
    set1.insert(8);
    set1.insert(12);
    set1.insert(7);
    set1.insert(-7);
    IntRange range1(3, 20);
    ArraySet set2(30);
    for (unsigned i = 0; i < 30; ++i)
        set2.insert(i);
    IntSet *sets[] =
        {
            &set1,
            &range1,
            &set2};
    std::cout << std::boolalpha << mon(sets, 3) << '\n';
    return 0;
}