#include <iostream>
#include <cstring>
#include "Beer.hpp"

void Beer::init(const char *_brand, unsigned _q)
{
    strcpy(brand, _brand);
    quantity = _q;
}

Beer::Beer()
{
    init("", 0);
    std::cout << "Beer created successfully!\n";
}

Beer::Beer(const char *_brand, unsigned _q)
{
    init(_brand, _q);
}

const char *Beer::getBrand() const
{
    return brand;
}

unsigned Beer::getQuantity() const
{
    return quantity;
}

void Beer::setBrand(const char *_name)
{
    strcpy(brand, _name);
}

void Beer::setQuantity(unsigned _q)
{
    quantity = _q;
}

void Beer::add(const Beer &b)
{
    if (!b.getQuantity())
    {
        std::cout << "<Beer has no quantity to be added.>\n";
        return;
    }
    strcat(brand, "&");
    strcat(brand, b.getBrand());
    quantity += b.getQuantity();
}

void Beer::print() const
{
    std::cout << "Brand: " << brand << "\tQuantity: " << quantity << '\n';
}

bool Beer::contains(const char *_brand) const
{
    return strstr(brand, _brand);
}