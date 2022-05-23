#include "Rectangle.hpp"

bool Rectangle::contains(const Point& P) const
{
    return P.getX() >= bottomLeft.getX() && P.getX() <= topRight.getX() &&
        P.getY() >= bottomLeft.getY() && P.getY() <= topRight.getY();
}

float Rectangle::area() const
{
    return (topRight.getY() - bottomLeft.getY()) * (topRight.getX() - bottomLeft.getX());
}

float Rectangle::perimeter() const
{
    return 2 * ((topRight.getY() - bottomLeft.getY())
        + (topRight.getX() - bottomLeft.getX()));
}

void Rectangle::print(std::ostream& os) const
{
    printType(os);
    os << " with bottom left corner " << bottomLeft << " and top right corner " << topRight;
}

void Rectangle::printType(std::ostream& os) const
{
    os << "Rectangle";
}
