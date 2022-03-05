#include <iostream>
#include <cstring>
#include "Sector.hpp"

Sector::Sector()
{
    companies = nullptr;
    companyCount = 0;
    std::cout << "<Sector created successfully.>\n";
}

void Sector::readSector()
{
    std::cout << "Enter count of companies in the sector: ";
    std::cin >> companyCount;
    if (companyCount)
        std::cin.ignore();
    companies = new (std::nothrow) Company *[companyCount];
    char buf[NAME_MAX];
    for (unsigned i = 0; i < companyCount; ++i)
    {
        std::cout << "Enter name for company #" << i + 1 << ":\n";
        std::cin.getline(buf, NAME_MAX);
        companies[i] = new (std::nothrow) Company(buf);
    }
}

void Sector::print() const
{
    for (unsigned i = 0; i < companyCount; ++i)
        companies[i]->print();
}

bool Sector::acquire(const char *buyer, const char *bought)
{
    Company *buyerC = nullptr, *boughtC = nullptr;
    unsigned i = 0;
    for (unsigned i = 0; i < companyCount && (!buyerC || !boughtC); ++i)
    {
        if (!buyerC && !strcmp(companies[i]->name, buyer))
            buyerC = companies[i];
        if (!boughtC && !strcmp(companies[i]->name, bought))
            boughtC = companies[i];
    }
    return buyerC && boughtC && buyerC->acquire(*boughtC);
}

Sector::~Sector()
{
    for (unsigned i = 0; i < companyCount; ++i)
        delete companies[i];
    delete companies;
    std::cout << "<Sector deleted successfully.>\n";
}