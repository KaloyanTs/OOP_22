#include <iostream>
#include <cstring>
#include "Company.hpp"

Company::Company()
{
    daughterCount = 0;
    daughters = new (std::nothrow) Company *[DAUGHTER_MAX];
    mother = nullptr;
    std::cout << "<Company created successfully.>\n";
}

Company::Company(const char *_name)
{
    strcpy(name, _name);
    daughters = new (std::nothrow) Company *[DAUGHTER_MAX];
    mother = nullptr;
    daughterCount = 0;
    std::cout << "<Company created successfully.>\n";
}

void Company::print() const
{
    std::cout << name << ':';
    if (!mother && !daughterCount)
    {
        std::cout << " has no parent or children\n";
        return;
    }
    if (mother)
        std::cout << " has " << mother->name << " as a parent";
    if (mother && daughterCount)
        std::cout << " and";
    if (daughterCount)
        std::cout << " has " << daughterCount
                  << " child";
    if (daughterCount > 1)
        std::cout << "ren";
    std::cout << '\n';
    for (unsigned i = 0; i < daughterCount; ++i)
        std::cout << '\t' << daughters[i]->name << '\n';
}

bool Company::isMyChild(const Company &c)
{
    unsigned i = 0;
    while (i < daughterCount && daughters[i] != &c)
        ++i;
    return i < daughterCount;
}

void Company::removeDaughter(Company &c)
{
    unsigned i = 0;
    while (i < daughterCount && daughters[i] != &c)
        ++i;
    if (i == daughterCount)
        return;
    c.mother = nullptr;
    for (unsigned j = i; j < daughterCount - 1; ++j)
        daughters[j] = daughters[j + 1];
    --daughterCount;
}

bool Company::acquire(Company &c)
{
    if (this->isMyChild(c) || c.isMyChild(*this) ||
        daughterCount + 1 + c.daughterCount > DAUGHTER_MAX)
    {
        std::cout << "<Acquiring not allowed.>\n";
        return false;
    }
    if (c.mother)
        c.mother->removeDaughter(c);
    c.mother = this;
    this->daughters[daughterCount++] = &c;
    for (unsigned i = 0; i < c.daughterCount; ++i)
    {
        this->daughters[daughterCount++] = c.daughters[i];
        c.daughters[i]->mother = this;
    }
    c.daughterCount = 0;
    std::cout << "<Acquiring done successfully.>\n";
    return true;
}

Company::~Company()
{
    // for (unsigned i = 0; i < daughterCount; ++i)
    //     delete daughters[i];
    delete[] daughters;
    daughters = nullptr;
    std::cout << '<' << name << " deleted successfully.>\n";
}