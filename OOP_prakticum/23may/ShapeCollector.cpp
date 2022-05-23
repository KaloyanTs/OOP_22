#include "ShapeCollector.hpp"

void ShapeCollector::clear()
{
    for (unsigned i = 0; i < size; ++i)
        delete arr[i];
    delete[] arr;
}

void ShapeCollector::expand()
{
    capacity <<= 1;
    Shape** newArr = new Shape * [capacity];
    for (unsigned i = 0; i < size; ++i)
        newArr[i] = arr[i];
    delete[] arr;
    arr = newArr;
}

void ShapeCollector::copy(const ShapeCollector& other)
{
    clear();
    size = other.size;
    capacity = other.capacity;
    arr = new Shape * [capacity];
    for (unsigned i = 0; i < size; ++i)
        arr[i] = other.arr[i]->clone();
}

ShapeCollector& ShapeCollector::operator=(const ShapeCollector& other)
{
    if (this != &other)
        copy(other);
    return *this;
}

ShapeCollector::~ShapeCollector()
{
    clear();
}

ShapeCollector& ShapeCollector::addShape(const Shape& s)
{
    if (size == capacity)
        expand();
    arr[size++] = s.clone();
    return *this;
}

void ShapeCollector::contains(const Point& p)
{
    unsigned count = 0;
    for (unsigned i = 0; i < size; ++i)
        if (arr[i]->contains(p))
            std::cout << ++count << ": " << *arr[i] << '\n';
}

void ShapeCollector::area() const
{
    for (unsigned i = 0; i < size; ++i)
    {
        std::cout << i + 1 << ": ";
        arr[i]->printType();
        std::cout << " - " << arr[i]->area() << '\n';
    }
}

void ShapeCollector::perimeter() const
{
    for (unsigned i = 0; i < size; ++i)
    {
        std::cout << i + 1 << ": ";
        arr[i]->printType();
        std::cout << " - " << arr[i]->perimeter() << '\n';
    }
}
