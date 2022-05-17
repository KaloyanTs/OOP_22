#include <iostream>
#include "GroupTicket.hpp"
#include "DiscountTicket.hpp"

int main()
{
    Ticket *arr[4] =
        {
            new Ticket,
            new DiscountTicket("dsfdsf", 45, "Az"),
            new Ticket("dsf", 4),
            new GroupTicket("dsf", 50, 10)};

    for (unsigned i = 0; i < 4; ++i)
        std::cout << *arr[i] << '\n';

    std::cout << calculateTotalPrice(arr, 4) << '\n';

    for (unsigned i = 0; i < 4; ++i)
        delete arr[i];

    return 0;
}