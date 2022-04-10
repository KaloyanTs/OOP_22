#ifndef __POINT_HPP
#define __POINT_HPP
#include <iostream>
#include <cassert>
#include <cstring>
#include <fstream>
const size_t COLOR_MAX = 16;
const char *const NO_COLOR = "no color";

class Point
{
    int x, y;
    char color[COLOR_MAX];

public:
    Point(int _x = 0, int y = 0, const char *_color = NO_COLOR);
    friend std::ostream &operator<<(std::ostream &os, const Point &P);
    friend std::istream &operator>>(std::istream &is, Point &P);
    void changeColor(const char *newColor = NO_COLOR) { strcpy(color, newColor); }
    friend class Matrix;
};

#endif