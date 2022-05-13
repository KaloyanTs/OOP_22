#include "Car.hpp"

bool Car::drive(double km)
{
    float neededFuel = km * LITRES_PER_KM;
    float currentFuel = tank.getFuel();
    if (tank.use(neededFuel))
    {
        mileage += km;
        return true;
    }
    mileage += (currentFuel / LITRES_PER_KM);
    return false;
}

Car *dragRace(Car *car1, Car *car2)
{
    bool c1 = car1->drive(DISTANCE);
    bool c2 = car2->drive(DISTANCE);
    if (!c1 && !c2)
        return nullptr;
    if (c1 && c2)
    {
        float c1Score = (float)car1->engine.getHorsePower() / car1->weight;
        float c2Score = (float)car2->engine.getHorsePower() / car2->weight;
        if (c1Score == c2Score)
            return nullptr;
        return (c1Score > c2Score ? car1 : car2);
    }
    return (c1 ? car1 : car2);
}

void Car::print(std::ostream &os) const
{
    os << "Weight: " << weight
       << "\tMileage: " << mileage
       << "\nEngine: " << engine
       << "\nTyres: " << tyres[0]
       << "\nBattery: " << battery
       << "\nTank: " << tank;
}