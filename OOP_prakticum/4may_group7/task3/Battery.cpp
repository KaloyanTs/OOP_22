#include "Battery.hpp"

void Battery::copy(const Battery &other)
{
    clear();
    batteryID = new char[strlen(other.batteryID) + 1];
    strcpy(batteryID, other.batteryID);
}

void Battery::clear()
{
    delete[] batteryID;
}

void Battery::print(std::ostream &os) const
{
    CarPart::print(os);
    os << " - " << capacity << " Ah";
}

Battery &Battery::operator=(const Battery &other)
{
    if (this != &other)
    {
        CarPart::copy(other);
        copy(other);
    }
    return *this;
}