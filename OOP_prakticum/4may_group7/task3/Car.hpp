#ifndef __CAR_HPP
#define __CAR_HPP
#include "Tyre.hpp"
#include "Engine.hpp"
#include "Battery.hpp"
#include "FuelTank.hpp"
const size_t TYRE_COUNT = 4;
const float LITRES_PER_KM = 1;
const float DISTANCE = 0.4;


class Car
{
    FuelTank tank;
    Engine engine;
    Tyre tyres[TYRE_COUNT];
    Battery battery;
    unsigned mileage;
    unsigned weight;

public:
    Car(const char *tankM = "unknown", const char *tankDes = "none.", unsigned tankCap = 0,
        const char *eM = "unknown", const char *eD = "none.", unsigned hp = 0,
        const char *tyreM = "unknown", const char *tyreE = "none.",
        unsigned tW = 0, unsigned tpr = 0, unsigned tDiam = 0,
        const char *bM = "unknown", const char *bD = "none.", unsigned bcap = 0,
        unsigned w = 0)
        : tank(tankM, tankDes, tankCap),
          engine(eM, eD, hp),
          tyres({Tyre(tyreM, tyreE, tW, tpr, tDiam),
                 Tyre(tyreM, tyreE, tW, tpr, tDiam),
                 Tyre(tyreM, tyreE, tW, tpr, tDiam),
                 Tyre(tyreM, tyreE, tW, tpr, tDiam)}),
          battery(bM, bD, bcap),
          mileage(0),
          weight(w) {}

    const FuelTank &getFuelTank() const { return tank; }

    bool drive(double km);

    friend Car *dragRace(Car *car1, Car *car2);

    void print(std::ostream &os = std::cout) const;
};

#endif