#include "EmployeeVector.hpp"

void EmployeeVector::resize(size_t newCap)
{
    assert(newCap > capacity);
    capacity = newCap;
    Employee **newList = new Employee *[capacity];
    assert(newList);
    for (unsigned i = 0; i < size; ++i)
        newList[i] = list[i];
    delete[] list;
    list = newList;
}

EmployeeVector::EmployeeVector(const EmployeeVector &eV)
    : list(new Employee *[eV.capacity]), size(eV.size), capacity(eV.capacity)
{
    for (unsigned i = 0; i < size; ++i)
        list[i] = new Employee(*eV.list[i]);
}

EmployeeVector::EmployeeVector(size_t cap)
    : list(new Employee *[cap]), size(0), capacity(cap)
{
    assert(list);
}

const EmployeeVector &EmployeeVector::addEmployee(const Employee &E)
{
    if (size == capacity)
        resize(2 * capacity + 1);
    list[size++] = new Employee(E);
    return *this;
}

const EmployeeVector &EmployeeVector::remove(const char *ID)
{
    unsigned i = 0;
    while (i < size && strcmp(list[i]->getID(), ID))
        ++i;
    if (i < size)
    {
        delete[] list[i];
        for (unsigned j = i; j < size - 1; ++j)
            list[j] = list[j + 1];
        --size;
    }
    return *this;
}

Employee &EmployeeVector::at(unsigned index) const
{
    assert(index < size);
    return *list[index];
}

void EmployeeVector::print() const
{
    std::cout << "Count: " << size << '\n';
    for (unsigned i = 0; i < size; ++i)
    {
        std::cout << '\t' << i + 1 << ": ";
        list[i]->print();
    }
}

EmployeeVector::~EmployeeVector()
{
    for (unsigned i = 0; i < size; ++i)
        delete list[i];
    delete[] list;
}

const EmployeeVector &EmployeeVector::operator=(const EmployeeVector &eV)
{
    if (this != &eV)
        copy(eV);
    return *this;
}

void EmployeeVector::copy(const EmployeeVector &eV)
{
    for (unsigned i = 0; i < size; ++i)
        delete[] list[i];
    delete[] list;
    size = eV.size;
    capacity = eV.capacity;
    list = new Employee *[eV.capacity];
    assert(list);
    for (unsigned i = 0; i < size; ++i)
        list[i] = new Employee(*eV.list[i]);
}

const EmployeeVector &EmployeeVector::operator+=(const EmployeeVector &other)
{
    for (unsigned i = 0; i < other.size; ++i)
        addEmployee(*other.list[i]);
    return *this;
}
