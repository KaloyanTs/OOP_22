#include <iostream>
#include <cstring>
#include "Shisha.hpp"

Shisha::Shisha()
{
    brand = taste = nullptr;
    price = 0;
}

Shisha::Shisha(const char *_brand, unsigned long _price, const char *_taste)
{
    brand = new (std::nothrow) char[strlen(_brand) + 1];
    taste = new (std::nothrow) char[strlen(_taste) + 1];
    if (!brand || !taste)
    {
        std::cout << "<Shisha couldn't be created.>\n";
        brand = taste = nullptr;
        price = 0;
        return;
    }
    strcpy(brand, _brand);
    strcpy(taste, _taste);
    price = _price;
    std::cout << "<Shisha created successfully.>\n";
}

void Shisha::read()
{
    char _taste[TASTE_MAX];
    char _brand[BRAND_MAX];
    std::cout << "Enter price of the shisha: ";
    std::cin >> price;
    std::cin.ignore();
    std::cout << "Enter brand of the shisha:\n";
    std::cin.getline(_brand, BRAND_MAX);
    std::cout << "Enter taste of the shisha:\n";
    std::cin.getline(_taste, BRAND_MAX);

    brand = new (std::nothrow) char[strlen(_brand) + 1];
    taste = new (std::nothrow) char[strlen(_taste) + 1];
    if (!brand || !taste)
    {
        std::cout << "<Shisha couldn't be created.>\n";
        brand = taste = nullptr;
        price = 0;
        return;
    }
    strcpy(brand, _brand);
    strcpy(taste, _taste);
    std::cout << "<Shisha created successfully.>\n";
}

const char *Shisha::getBrand() const
{
    return brand;
}

const char *Shisha::getTaste() const
{
    return taste;
}

unsigned long Shisha::getPrice() const
{
    return price;
}

void Shisha::setPrice(unsigned long _price)
{
    price = _price;
    std::cout << "<Shisha's price modified successfully.>\n";
}

void Shisha::setBrand(const char *_brand)
{
    char *oldBrand = brand;
    brand = new (std::nothrow) char[strlen(_brand) + 1];
    if (!brand)
    {
        std::cout << "<Shisha's brand couldn't be modified.>\n";
        brand = oldBrand;
        return;
    }
    delete[] oldBrand;
    strcpy(brand, _brand);
    std::cout << "<Shisha's brand modified successfully.>\n";
}

bool Shisha::areSame(const Shisha &s) const
{
    return !strcmp(brand, s.getBrand()) &&
           !strcmp(taste, s.getTaste()) &&
           price == s.getPrice();
}

void Shisha::setTaste(const char *_taste)
{
    char *oldTaste = taste;
    taste = new (std::nothrow) char[strlen(_taste) + 1];
    if (!taste)
    {
        std::cout << "<Shisha's brand couldn't be modified.>\n";
        taste = oldTaste;
        return;
    }
    delete[] oldTaste;
    strcpy(taste, _taste);
    std::cout << "<Shisha's taste modified successfully.>\n";
}

void Shisha::print() const
{
    std::cout << "Brand: " << brand
              << "\tTaste: " << taste
              << "\tPrice: " << price << '\n';
}

Shisha::~Shisha()
{
    delete[] brand;
    delete[] taste;
    std::cout << "<Shisha deleted successfully.>\n";
}
