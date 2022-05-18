#include "Worker.hpp"

Worker::Worker(const Worker &other)
    : name(nullptr)
{
    copy(other);
}

Worker &Worker::operator=(const Worker &other)
{
    if (this != &other)
        copy(other);
    return *this;
}

Worker::~Worker()
{
    clear();
}

void Worker::print(std::ostream &os, unsigned level) const
{
    for (unsigned i = 0; i < level; ++i)
        os << '\t';
    os << name << ", aged " << age
       << " works from " << months
       << " months and receives salary " << salary;
}

void Worker::clear()
{
    delete[] name;
}

void Worker::copy(const Worker &other)
{
    clear();
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    age = other.age;
    salary = other.salary;
    months = other.months;
}

std::ostream &operator<<(std::ostream &os, const Worker &W)
{
    W.print(os);
    return os;
}

bool Worker::operator==(const Worker &other) const
{
    return (age == other.age &&
            salary == other.salary &&
            months == other.months &&
            !strcmp(name, other.name));
}