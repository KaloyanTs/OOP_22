#include "Component.hpp"

void Component::print(std::ostream &os) const
{
    os << "Name: " << label << "\tPrice: " << price();
}
