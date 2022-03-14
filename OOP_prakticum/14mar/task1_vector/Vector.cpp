#include "Vector.hpp"

Vector::Vector()
{
    size = 0;
    capacity = STEP_CAPACITY;
    arr = new (std::nothrow) int[capacity];
    if (!arr)
    {
        std::cout << "<Vector could not be created properly.>\n";
        capacity = 0;
    }
    else
        std::cout << "<Vector created successfully.>\n";
}

Vector::Vector(size_t _capacity)
{
    size = 0;
    capacity = _capacity;
    arr = new (std::nothrow) int[_capacity];
    if (!arr)
        capacity = 0;
    if (capacity == _capacity)
        std::cout << "<Vector could not be created properly.>\n";
    else
        std::cout << "Vector created successfully.\n";
}

void Vector::copy(const Vector &V)
{
    int *newArr = new (std::nothrow) int[V.capacity];
    if (!newArr)
    {
        std::cout << "<Vector could not be copied.>\n";
        return;
    }
    for (unsigned i = 0; i < V.size; ++i)
        newArr[i] = V.arr[i];
    dealloc(arr);
    size = V.size;
    capacity = V.capacity;
    arr = newArr;
    std::cout << "<Vector copied successfully.>\n";
}

void Vector::dealloc(int *&array)
{
    delete[] array;
    array = nullptr;
}

Vector::Vector(const Vector &V)
{
    arr = nullptr;
    copy(V);
    std::cout << "<Vector created succesfully.>\n";
}

const Vector &Vector::operator=(const Vector &V)
{
    if (this != &V)
        copy(V);
    std::cout << "<Equalizing done successfully.>\n";
    return *this;
}

void Vector::print() const
{
    std::cout << "Capacity: " << capacity << "\tSize: " << size << '\n';
    for (unsigned i = 0; i < size; ++i)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
}

int &Vector::at(unsigned index) const
{
    assert(index < size);
    return arr[index];
}

bool Vector::pushBack(int element)
{
    if (size == capacity && !reserve(capacity + STEP_CAPACITY))
        return false;
    arr[size++] = element;
    return true;
}

bool Vector::erase(unsigned index)
{
    if (index >= size)
        return false;
    while (index < size)
    {
        arr[index] = arr[index + 1];
        ++index;
    }
    --size;
    return true;
}

bool Vector::reserve(unsigned newCapacity)
{
    assert(newCapacity >= capacity);
    int *newArr = new (std::nothrow) int[newCapacity];
    if (!newArr)
        return false;
    for (unsigned i = 0; i < size; ++i)
        newArr[i] = arr[i];
    capacity = newCapacity;
    dealloc(arr);
    arr = newArr;
    return true;
}

Vector::~Vector()
{
    dealloc(arr);
    std::cout << "<Vector deleted successfully.>\n";
}