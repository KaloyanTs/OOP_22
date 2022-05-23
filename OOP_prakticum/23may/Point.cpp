#include "Point.hpp"

std::ostream& operator<<(std::ostream& os, const Point& P)
{
    return os << '(' << P.getX() << ", " << P.getY() << ')';
}

float Point::distanceTo(const Point& other)const
{
    return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
}
