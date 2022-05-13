#include <iostream>
#include "Car.hpp"

int main()
{
    Tyre t("erte", "best tyre", 123, 324, 23);
    Engine e("erde", "best engine", 200);
    Battery b("erde", "long life battery", 1000, "RTRETDFVT");

    CarPart *arr[3] = {&t, &e, &b};
    for (unsigned i = 0; i < 3; ++i)
        std::cout << *arr[i] << '\n';

    Car volvo("BestTank", "none.", 100, "Volvo", "none.",
              200,
              "Michelin", "none.",
              100, 100, 100,
              "bat", "none.", 1000, 400);

    Car VW("BestTank", "none.", 100, "VW", "none.",
           150, "Michelin", "none.",
           100, 100, 100,
           "bat", "none.", 1000, 650);

    Car *winner = dragRace(&volvo, &VW);
    if (!winner)
        std::clog << "No winnner.\n";
    else
    {
        std::clog << "Winner is:\n";
        winner->print();
    }

    return 0;
}