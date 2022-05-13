#ifndef __FUELTANK_HPP
#define __FUELTANK_HPP
#include "CarPart.hpp"

class FuelTank : public CarPart
{
    float fuel;
    float capacity;

public:
    FuelTank(const char *m = "unknown", const char *d = "none.",
             float c = 0)
        : CarPart(m, d), fuel(c), capacity(c) {}

    void print(std::ostream &os = std::cout) const;

    bool use(double toUse);
    FuelTank &fill(double toFill);
    float getFuel() const { return fuel; }
};

#endif