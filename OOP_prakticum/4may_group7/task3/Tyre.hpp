#ifndef __TYRE_HPP
#define __TYRE_HPP
#include "CarPart.hpp"

class Tyre : public CarPart
{
    unsigned width;
    unsigned profile;
    unsigned diameter;

public:
    Tyre(const char *m = "unknown", const char *d = "none.",
         unsigned w = 0, unsigned p = 0, unsigned diam = 0)
        : CarPart(m, d), width(w), profile(p), diameter(diam) {}

    void print(std::ostream &os = std::cout) const;
};

#endif