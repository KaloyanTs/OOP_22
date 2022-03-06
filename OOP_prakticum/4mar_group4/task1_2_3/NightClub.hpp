#pragma once
#include "Balloon.hpp"
#include "Shisha.hpp"
#include "Alcohol.hpp"
const unsigned QUANTITY_MAX = 1024;

class NightClub
{
    Balloon **balloons;
    Shisha **shishas;
    Alcohol **alcohols;
    unsigned balloonCount;
    unsigned alcoholCount;
    unsigned shishasCount;
    void init();

public:
    NightClub();
    bool addBalloon();
    void removeBalloon(const char *color);
    bool checkBalloon(const Balloon &b);
    bool addShisha();
    void removeShisha(const char *brand, const char *taste);
    bool checkShisha(const Shisha &s);
    bool addAlcohol();
    void removeAlcohol(const char *name);
    bool checkAlcohol(const Alcohol &a);
    void print() const;
    ~NightClub();
};