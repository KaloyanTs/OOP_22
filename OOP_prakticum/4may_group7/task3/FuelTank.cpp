#include "FuelTank.hpp"

void FuelTank::print(std::ostream &os) const
{
    CarPart::print(os);
    os << " - " << fuel << '/' << capacity;
}

bool FuelTank::use(double toUse)
{
    if (toUse > fuel)
        return fuel = 0;
    else
        return fuel -= toUse;
}

FuelTank &FuelTank::fill(double toFill)
{
    fuel += toFill;
    if (fuel > capacity)
        fuel = capacity;
    return *this;
}