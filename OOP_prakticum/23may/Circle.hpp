#ifndef __CIRCLE_HPP
#define __CIRCLE_HPP
#include "Shape.hpp"

class Circle :public Shape
{
	static const float PI;
	Point center;
	float radius;
public:
	Circle(const Point& p, float r = 0) :center(p), radius(r){}
	Circle* clone()const { return new Circle(*this); }
	bool contains(const Point& P)const;
	float area()const;
	float perimeter()const;
	void print(std::ostream& os = std::cout)const;
	virtual void printType(std::ostream& os = std::cout)const;
};

#endif 
