#include "Bed.hpp"

void Bed::print(std::ostream &os) const
{
    os << "Bed ";
    Furniture::print(os);
}

unsigned Bed::calculatePrice() const
{
    return getLength() * getHeight() * getPriceConst();
}