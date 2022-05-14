#include <iostream>
#include "Table.hpp"
#include "Bed.hpp"
#include "Chair.hpp"

int main()
{
    Table p(100, 40, 140, KITCHEN);
    std::cout << p << '\n';
    std::cout << Table(100, 40, 140, KITCHEN) << '\n';
    Table p2(100, 40, 140, KITCHEN);
    std::cout << p2 << '\n';

    Furniture *f[] =
        {new Bed(200, 60, 50),
         new Chair(40, 40, 145, WOODEN),
         new Table(140, 140, 130, HALL)};

    size_t count = sizeof(f) / sizeof(*f);
    for (unsigned i = 0; i < count; ++i)
    {
        std::cout << *f[i] << '\n';
        delete f[i];
    }

    return 0;
}
