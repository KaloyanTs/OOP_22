#ifndef __RECTANGLE_HPP
#define __RECTANGLE_HPP
#include "Shape.hpp"

class Rectangle :public Shape
{
	Point bottomLeft, topRight;
public:
	Rectangle(const Point& p1, const Point& p2) :bottomLeft(std::min(p1.getX(), p2.getX()), std::min(p1.getY(), p2.getY())),
		topRight(std::max(p1.getX(), p2.getX()), std::max(p1.getY(), p2.getY())) {}
	Rectangle* clone()const { return new Rectangle(*this); }
	bool contains(const Point& P)const;
	float area()const;
	float perimeter()const;
	void print(std::ostream& os = std::cout)const;
	void printType(std::ostream& os = std::cout)const;
};

#endif