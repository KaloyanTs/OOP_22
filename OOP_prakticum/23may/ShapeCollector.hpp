#ifndef __SHAPE_COLLECTOR_HPP
#define __SHAPE_COLLECTOR_HPP
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Triangle.hpp"

class ShapeCollector
{
	static const unsigned INIT_CAPACITY = 2;
	Shape **arr;
	size_t size, capacity;

	void clear();
	void expand();
	void copy(const ShapeCollector &other);

public:
	ShapeCollector(size_t cap = INIT_CAPACITY) : arr(new Shape *[cap]), size(0), capacity(cap) {}
	ShapeCollector(const ShapeCollector &other) : arr(nullptr), size(0) { copy(other); }
	ShapeCollector &operator=(const ShapeCollector &other);
	~ShapeCollector();

	ShapeCollector &addShape(const Shape &s);
	void contains(const Point &p);
	void area() const;
	void perimeter() const;
};

#endif