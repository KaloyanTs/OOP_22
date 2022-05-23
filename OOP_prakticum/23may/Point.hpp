#ifndef __POINT_HPP
#define __POINT_HPP
#include <iostream>
#include <cmath>

class Point
{
	float x, y;
public:
	Point(float _x = 0, float _y = 0) :x(_x), y(_y) {}
	float getX()const { return x; }
	float getY()const { return y; }
	float distanceTo(const Point& other)const;
};

std::ostream& operator<<(std::ostream& os, const Point& P);

#endif