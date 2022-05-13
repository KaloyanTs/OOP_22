#include "CarPart.hpp"

unsigned CarPart::ID_COUNTER = 0;

void CarPart::copy(const CarPart &other)
{
    clear();
    ID = ++ID_COUNTER;
    manifacturer = new char[strlen(other.manifacturer) + 1];
    description = new char[strlen(other.description) + 1];
    strcpy(manifacturer, other.manifacturer);
    strcpy(description, other.description);
}

void CarPart::clear()
{
    delete[] manifacturer;
    delete[] description;
}

CarPart::CarPart(const CarPart &other)
    : manifacturer(nullptr), description(nullptr)
{
    copy(other);
}

CarPart &CarPart::operator=(const CarPart &other)
{
    if (this != &other)
        copy(other);
    return *this;
}

CarPart::~CarPart()
{
    clear();
    --ID_COUNTER;
}

void CarPart::print(std::ostream &os) const
{
    os << ID << " by " << manifacturer
       << " - " << description;
}

std::ostream &operator<<(std::ostream &os, const CarPart &cP)
{
    cP.print();
    return os;
}