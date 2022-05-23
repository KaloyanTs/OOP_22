#include "Triangle.hpp"

bool Triangle::contains(const Point &P) const
{
    return area() == Triangle(vertices[0], vertices[1], P).area() +
                         Triangle(vertices[1], vertices[2], P).area() +
                         Triangle(vertices[0], vertices[2], P).area();
}

float Triangle::area() const
{
    /*
    x0 y0 1
    x1 y1 1
    x2 y2 1
        */
    float A = vertices[0].getX() * vertices[1].getY() +
              vertices[1].getX() * vertices[2].getY() +
              vertices[0].getY() * vertices[2].getX() -
              vertices[2].getX() * vertices[1].getY() -
              vertices[1].getX() * vertices[0].getY() -
              vertices[0].getX() * vertices[2].getY();
    A /= 2;
    return (A < 0 ? -A : A);
}

float Triangle::perimeter() const
{
    return vertices[0].distanceTo(vertices[1]) +
           vertices[0].distanceTo(vertices[2]) +
           vertices[1].distanceTo(vertices[2]);
}

void Triangle::print(std::ostream &os) const
{
    printType(os);
    os << " ( ";
    for (unsigned i = 0; i < 3; ++i)
    {
        if (i)
            os << ", ";
        os << vertices[i];
    }
    os << " )";
}

void Triangle::printType(std::ostream &os) const
{
    os << "Triangle";
}
