#include "Table.hpp"

void Table::print(std::ostream &os) const
{
    os << "Table of type " << type << ' ';
    Furniture::print(os);
}

unsigned Table::calculatePrice() const
{
    return getWidth() * getLength() * getPriceConst();
}

std::ostream &operator<<(std::ostream &os, TableType t)
{
    if (t == KITCHEN)
        return os << "Kitchen";
    if (t == HALL)
        return os << "Hall";
    return os << "None";
}