#include <iostream>
#include <cstring>
#include "NightClub.hpp"

NightClub::NightClub()
{
    balloons = nullptr;
    balloonCount = 0;
    alcohols = nullptr;
    alcoholCount = 0;
    shishas = nullptr;
    shishasCount = 0;
    std::cout << "<NightClub created successfully.>\n";
}

void NightClub::init()
{
    if (!balloons)
    {
        balloons = new (std::nothrow) Balloon *[QUANTITY_MAX];
        shishas = new (std::nothrow) Shisha *[QUANTITY_MAX];
        alcohols = new (std::nothrow) Alcohol *[QUANTITY_MAX];
    }
    std::cout << "<Night club storage initialized.>\n";
}

bool NightClub::addBalloon()
{
    init();
    balloons[balloonCount] = new (std::nothrow) Balloon;
    if (balloonCount < QUANTITY_MAX)
    {
        balloons[balloonCount++]->read();
        std::cout << "<Balloon added successfully.>\n";
        return true;
    }
    else
    {
        std::cout << "<Balloon couldn't be added.>\n";
        return false;
    }
}

void NightClub::removeBalloon(const char *color)
{
    unsigned i = 0;
    while (i < balloonCount && strcmp(balloons[i]->getColor(), color))
        ++i;
    if (i < balloonCount)
    {
        delete balloons[i];
        for (unsigned j = i; j < balloonCount - 1; ++j)
            balloons[j] = balloons[j + 1];
        --balloonCount;
        std::cout << "<Balloon removed successfully.>\n";
    }
    else
        std::cout << "<No such balloon found.>\n";
}

bool NightClub::checkBalloon(const Balloon &res)
{
    unsigned i = 0;
    while (i < balloonCount && !res.areSame(*balloons[i]))
        ++i;
    return i < balloonCount;
}

bool NightClub::addShisha()
{
    init();
    shishas[shishasCount] = new (std::nothrow) Shisha;
    if (shishasCount < QUANTITY_MAX)
    {
        shishas[shishasCount++]->read();
        std::cout << "<Shisha added successfully.>\n";
        return true;
    }
    else
    {
        std::cout << "<Shisha couldn't be added.>\n";
        return false;
    }
}

void NightClub::removeShisha(const char *brand, const char *taste)
{
    unsigned i = 0;
    while (i < shishasCount &&
           (strcmp(shishas[i]->getBrand(), brand) ||
            strcmp(shishas[i]->getTaste(), taste)))
        ++i;
    if (i < shishasCount)
    {
        delete shishas[i];
        for (unsigned j = i; j < shishasCount - 1; ++j)
            shishas[j] = shishas[j + 1];
        --shishasCount;
        std::cout << "<Shisha removed successfully.>\n";
    }
    else
        std::cout << "<No such Shisha found.>\n";
}

bool NightClub::checkShisha(const Shisha &res)
{
    unsigned i = 0;
    while (i < shishasCount && !res.areSame(*shishas[i]))
        ++i;
    return i < shishasCount;
}

bool NightClub::addAlcohol()
{
    init();
    alcohols[alcoholCount] = new (std::nothrow) Alcohol;
    if (alcoholCount < QUANTITY_MAX)
    {
        alcohols[alcoholCount++]->read();
        std::cout << "<Alcohol added successfully.>\n";
        return true;
    }
    else
    {
        std::cout << "<Alcohol couldn't be added.>\n";
        return false;
    }
}

void NightClub::removeAlcohol(const char *name)
{
    unsigned i = 0;
    while (i < alcoholCount && strcmp(alcohols[i]->getName(), name))
        ++i;
    if (i < alcoholCount)
    {
        delete alcohols[i];
        for (unsigned j = i; j < alcoholCount - 1; ++j)
            alcohols[j] = alcohols[j + 1];
        --alcoholCount;
        std::cout << "<Alcohol removed successfully.>\n";
    }
    else
        std::cout << "<No such Alcohol found.>\n";
}

bool NightClub::checkAlcohol(const Alcohol &res)
{
    unsigned i = 0;
    while (i < alcoholCount && !res.areSame(*alcohols[i]))
        ++i;
    return i < alcoholCount;
}

void NightClub::print() const
{
    std::cout << "There "
              << (balloonCount == 1 ? "is " : "are ")
              << balloonCount
              << (balloonCount == 1 ? " balloon " : " balloons ")
              << "in the club"
              << (balloonCount ? ':' : '.')
              << '\n';
    for (unsigned i = 0; i < balloonCount; ++i)
    {
        std::cout << '\t';
        balloons[i]->print();
    }
    std::cout << "There "
              << (shishasCount == 1 ? "is " : "are ")
              << shishasCount
              << (shishasCount == 1 ? " shisha " : " shishas ")
              << "in the club"
              << (shishasCount ? ':' : '.')
              << '\n';
    for (unsigned i = 0; i < shishasCount; ++i)
    {
        std::cout << '\t';
        shishas[i]->print();
    }
    std::cout << "There "
              << (alcoholCount == 1 ? "is " : "are ")
              << alcoholCount
              << (alcoholCount == 1 ? " bottle " : " bottles ")
              << "of alcohol in the club"
              << (alcoholCount ? ':' : '.')
              << '\n';
    for (unsigned i = 0; i < alcoholCount; ++i)
    {
        std::cout << '\t';
        alcohols[i]->print();
    }
}

NightClub::~NightClub()
{
    for (unsigned i = 0; i < balloonCount; ++i)
        delete balloons[i];
    delete[] balloons;
    for (unsigned i = 0; i < shishasCount; ++i)
        delete shishas[i];
    delete[] shishas;
    for (unsigned i = 0; i < alcoholCount; ++i)
        delete alcohols[i];
    delete[] alcohols;
    std::cout << "<Night club deleted successfully.>\n";
}
