#ifndef __SHAPE_HPP
#define __SHAPE_HPP
#include "Point.hpp"

class Shape
{
public:
	virtual ~Shape(){};
	virtual Shape *clone() const = 0;
	virtual bool contains(const Point &P) const = 0;
	virtual float area() const = 0;
	virtual float perimeter() const = 0;
	virtual void print(std::ostream &os = std::cout) const = 0;
	virtual void printType(std::ostream &os = std::cout) const = 0;
};

std::ostream &operator<<(std::ostream &os, const Shape &f);

#endif