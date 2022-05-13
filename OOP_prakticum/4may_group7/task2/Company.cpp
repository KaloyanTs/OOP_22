#include "Company.hpp"

void Company::copy(const Company &other)
{
    clear();
    capacity = other.capacity;
    size = other.size;
    workers = new Worker *[capacity];
    for (unsigned i = 0; i < size; ++i)
        workers[i] = new Worker(*other.workers[i]);
}

void Company::expand()
{
    capacity *= 2;
    Worker **newArr = new Worker *[capacity];
    for (unsigned i = 0; i < size; ++i)
        newArr[i] = workers[i];
    delete[] workers;
    workers = newArr;
}

void Company::clear()
{
    for (unsigned i = 0; i < size; ++i)
        delete workers[i];
    delete[] workers;
}

Company::Company(const Company *other)
    : workers(nullptr)
{
    copy(other);
}

Company &Company::operator=(const Company &other)
{
    if (this != &other)
        copy(other);
    return *this;
}

Company::~Company()
{
    clear();
}

void Company::addWorker(const Worker &W)
{
    if (size == capacity)
        expand();
    workers[size++] = new Worker(W);
}

bool Company::isInCompany(const char *name) const
{
    unsigned i = 0;
    while (i < size && strcmp(name, workers[i]->getName()))
        ++i;
    return i < size;
}

void Company::showWorkerInfo(const char *name, std::ostream &os) const
{
    unsigned i = 0;
    while (i < size && strcmp(name, workers[i]->getName()))
        ++i;
    if (i < size)
        os << "Age: " << workers[i]->getAge()
           << "\tSalary: " << workers[i]->getSalary() << '\n';
}

void Company::print(std::ostream &os) const
{
    for (unsigned i = 0; i < size; ++i)
        os << i + 1 << ": " << *workers[i] << '\n';
}

std::ostream &operator<<(std::ostream &os, const Company &C)
{
    C.print(os);
    return os;
}