#include <iostream>
#include <cstring>
#include "Balloon.hpp"

Balloon::Balloon(const char *_color, unsigned _price)
{
    color = new (std::nothrow) char[strlen(_color) + 1];
    if (!color)
    {
        std::cout << "<Balloon couldn't be created.>\n";
        color = nullptr;
        price = 0;
        return;
    }
    strcpy(color, _color);
    price = _price;
    std::cout << "<Balloon created successfully.>\n";
}

void Balloon::print() const
{
    std::cout << "Color: " << color << "\tPrice: " << price << '\n';
}

void Balloon::read()
{
    std::cout << "Enter price of the balloon: ";
    std::cin >> price;
    std::cin.ignore();
    std::cout << "Enter color of the balloon:\n";
    char _color[COLOR_MAX];
    std::cin.getline(_color, COLOR_MAX);
    color = new (std::nothrow) char[strlen(_color) + 1];
    if (!color)
    {
        std::cout << "<Balloon couldn't be created.>\n";
        color = nullptr;
        price = 0;
        return;
    }
    strcpy(color, _color);
    std::cout << "<Balloon created successfully.>\n";
}

const char *Balloon::getColor() const
{
    return color;
}

unsigned Balloon::getPrice() const
{
    return price;
}

Balloon::~Balloon()
{
    delete[] color;
    std::cout << "<Balloon deleted successfully.>\n";
}

Balloon::Balloon()
{
    color = nullptr;
    price = 0;
    std::cout << "<Balloon created successfully.>\n";
}

void Balloon::setPrice(unsigned _price)
{
    price = _price;
    std::cout << "Balloon;s price modified successfully.>\n";
}

void Balloon::setColor(const char *_color)
{
    char *oldColor = color;
    color = new (std::nothrow) char[strlen(_color) + 1];
    if (!color)
    {
        std::cout << "<Balloon's color couldn't be modified.>\n";
        color = oldColor;
        price = 0;
        return;
    }
    delete[] oldColor;
    strcpy(color, _color);
    std::cout << "<Balloon's color modified successfully.>\n";
}

bool Balloon::areSame(const Balloon &b) const
{
    return price == b.getPrice() && !strcmp(color, b.getColor());
}
