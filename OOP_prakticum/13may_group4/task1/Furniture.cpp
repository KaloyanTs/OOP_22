#include "Furniture.hpp"

unsigned Furniture::ID_COUNTER = 0;

void Furniture::print(std::ostream &os) const
{
    os << "with ID " << ID
       << ", dimensions " << length << '/' << width << '/' << height;
}

std::ostream &operator<<(std::ostream &os, const Furniture &F)
{
    F.printAll(os);
    return os;
}

void Furniture::printAll(std::ostream &os) const
{
    print();
    os << " and price " << calculatePrice();
}