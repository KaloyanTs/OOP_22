#ifndef __ENGINE_HPP
#define __ENGINE_HPP
#include "CarPart.hpp"

class Engine : public CarPart
{
    unsigned horsePower;

public:
    Engine(const char *m = "unknown", const char *d = "none.",
           unsigned hp = 0)
        : CarPart(m, d), horsePower(hp) {}

    void print(std::ostream &os = std::cout) const;

    unsigned getHorsePower() const { return horsePower; }
};

#endif