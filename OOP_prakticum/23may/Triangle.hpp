#ifndef __TRIANGLE_HPP
#define __TRIANGLE_HPP
#include "Shape.hpp"

class Triangle :public Shape
{
	Point vertices[3];
public:
	Triangle(const Point& A, const Point& B, const Point& C) {vertices[0] = A; vertices[1] = B; vertices[2] = C; }
	Triangle* clone()const { return new Triangle(*this); }
	bool contains(const Point& P)const;
	float area()const;
	float perimeter()const;
	void print(std::ostream& os = std::cout)const;
	void printType(std::ostream& os = std::cout)const;
};

#endif
