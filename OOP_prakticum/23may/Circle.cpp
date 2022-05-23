#include "Circle.hpp"

const float Circle::PI = 4 * atan(1);

bool Circle::contains(const Point& P) const
{
    return P.distanceTo(center) <= radius;
}

float Circle::area() const
{
    return PI * radius * radius;
}

float Circle::perimeter() const
{
    return 2 * PI * radius;
}

void Circle::print(std::ostream& os) const
{
    printType(os);
    os <<" with center " << center << " and radius " << radius;
}

void Circle::printType(std::ostream& os) const
{
    os << "Circle";
}
