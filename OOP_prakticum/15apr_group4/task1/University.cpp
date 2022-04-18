#include "University.hpp"

void University::copy(const University &other)
{
}

void University::resize(unsigned newCap)
{
}

void University::clear()
{
}

University::University(const University &other)
    : students(nullptr)
{
    copy(other);
}

University::~University()
{
    clear();
}
