#include <iostream>
#include "ShapeCollector.hpp"

int main()
{
	ShapeCollector sklad;
	Point A(4, 3);
	Point B(0, 0);
	Point C(1, -10);
	Circle c(A, 5);
	Triangle t1(A, B, C);
	sklad.addShape(c).addShape(t1);
	sklad.area();
	sklad.perimeter();
	sklad.contains(Point(2.5, 0.5));
	return 0;
}