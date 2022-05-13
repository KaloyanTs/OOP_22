#include "Tyre.hpp"

void Tyre::print(std::ostream &os) const
{
    CarPart::print(os);
    os << " - " << width << '/' << profile << 'R' << diameter;
}