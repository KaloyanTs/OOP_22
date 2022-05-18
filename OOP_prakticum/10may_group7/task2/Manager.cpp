#include "Manager.hpp"

Manager::Manager(const Manager &other)
    : size(0), arr(nullptr), Worker(other), companyName(nullptr)
{
    copy(other);
}

Manager &Manager::operator=(const Manager &other)
{
    if (this != &other)
    {
        Worker::copy(other);
        copy(other);
    }
    return *this;
}

Manager::~Manager()
{
    clear();
}

Manager &Manager::addWorker(const Worker &ptr)
{
    if (size == capacity)
        expand();
    arr[size++] = ptr.clone();
    return *this;
}

void Manager::print(std::ostream &os, unsigned level) const
{
    Worker::print(os, level);
    os << '\n';
    for (unsigned i = 0; i < level; ++i)
        os << '\t';
    os << "\tManager in " << companyName;
    if (size)
    {
        os << '\n';
        for (unsigned i = 0; i < level; ++i)
            os << '\t';
        os << "\tmanages:\n";
    }
    for (unsigned i = 0; i < size; ++i)
    {
        arr[i]->print(os, level + 1);
        os << '\n';
    }
}

void Manager::clear()
{
    delete[] companyName;
    for (unsigned i = 0; i < size; ++i)
        delete arr[i];
    delete[] arr;
}

void Manager::expand()
{
    capacity <<= 1;
    Worker **newArr = new Worker *[capacity];
    for (unsigned i = 0; i < size; ++i)
        newArr[i] = arr[i];
    delete[] arr;
    arr = newArr;
}

void Manager::copy(const Manager &other)
{
    clear();
    companyName = new char[strlen(other.companyName) + 1];
    strcpy(companyName, other.companyName);
    size = other.size;
    capacity = other.capacity;
    arr = new Worker *[capacity];
    for (unsigned i = 0; i < size; ++i)
        arr[i] = other.arr[i]->clone();
}