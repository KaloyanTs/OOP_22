#include <iostream>
#include <cstring>
#include "Alcohol.hpp"

Alcohol::Alcohol()
{
    name = nullptr;
    price = 0;
}

Alcohol::Alcohol(const char *_name, unsigned long _price)
{
    name = new (std::nothrow) char[strlen(_name) + 1];
    if (!name)
    {
        std::cout << "<Alcohol couldn't be created.>\n";
        name = nullptr;
        price = 0;
        return;
    }
    strcpy(name, _name);
    price = _price;
    std::cout << "<Alcohol created successfully.>\n";
}

void Alcohol::read()
{
    char _name[NAME_MAX];
    std::cout << "Enter price of the alcohol: ";
    std::cin >> price;
    std::cin.ignore();
    std::cout << "Enter name of the alcohol:\n";
    std::cin.getline(_name, NAME_MAX);

    name = new (std::nothrow) char[strlen(_name) + 1];
    if (!name)
    {
        std::cout << "<Alcohol couldn't be created.>\n";
        name = nullptr;
        price = 0;
        return;
    }
    strcpy(name, _name);
    std::cout << "<Alcohol created successfully.>\n";
}

const char *Alcohol::getName() const
{
    return name;
}

unsigned long Alcohol::getPrice() const
{
    return price;
}

void Alcohol::setPrice(unsigned long _price)
{
    price = _price;
    std::cout << "<Alcohol's price modified successfully.>\n";
}

void Alcohol::setName(const char *_name)
{
    char *oldName = name;
    name = new (std::nothrow) char[strlen(_name) + 1];
    if (!name)
    {
        std::cout << "<Alcohol's name couldn't be modified.>\n";
        name = oldName;
        return;
    }
    delete[] oldName;
    strcpy(name, _name);
    std::cout << "<Alcohol's name modified successfully.>\n";
}

bool Alcohol::areSame(const Alcohol &a) const
{
    return !strcmp(name, a.getName()) && price == a.getPrice();
}

void Alcohol::print() const
{
    std::cout << "Name: " << name << "\tPrice: " << price << '\n';
}

Alcohol::~Alcohol()
{
    delete[] name;
    std::cout << "<Alcohol deleted successfully.>\n";
}
