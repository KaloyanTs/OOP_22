#ifndef __BATTERY_HPP
#define __BATTERY_HPP
#include "CarPart.hpp"

class Battery : public CarPart
{
    unsigned capacity;
    char *batteryID;

    void clear();

protected:
    void copy(const Battery &other);

public:
    Battery(const char *m = "unknown", const char *d = "none.",
            unsigned c = 0, const char *bID = "NONE")
        : CarPart(m, d), capacity(c), batteryID(new char[strlen(bID) + 1])
    {
        strcpy(batteryID, bID);
    }
    Battery(const Battery &other) : batteryID(nullptr) { copy(other); }
    Battery &operator=(const Battery &other);
    ~Battery() { clear(); }

    void print(std::ostream &os = std::cout) const;
};

#endif