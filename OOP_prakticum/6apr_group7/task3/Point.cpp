#include "Point.hpp"

Point::Point(int _x, int _y, const char *_color)
    : x(_x), y(_y)
{
    strcpy(color, _color);
}

std::ostream &operator<<(std::ostream &os, const Point &P)
{
    return os << '(' << P.x << ',' << P.y << ',' << P.color << ')';
}

std::istream &operator>>(std::istream &is, Point &P)
{
    char buf;
    return is >> buf >> P.x >> buf >> P.y >> buf >> P.color >> buf;
}
