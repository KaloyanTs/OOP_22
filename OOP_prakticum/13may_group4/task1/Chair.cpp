#include "Chair.hpp"

void Chair::print(std::ostream &os) const
{
    os << "Chair of type " << type << ' ';
    Furniture::print(os);
}

unsigned Chair::calculatePrice() const
{
    return getHeight() * getWidth() * getPriceConst();
}

std::ostream &operator<<(std::ostream &os, ChairType t)
{
    if (t == WOODEN)
        return os << "Wooden";
    if (t == METAL)
        return os << "Metal";
    if (t == PLASTIC)
        return os << "Plastic";
    return os << "None";
}