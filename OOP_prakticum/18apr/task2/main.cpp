#include <iostream>
#include "Spacecraft.hpp"

int main()
{
    Spacecraft *sp[6];

    sp[0] = new Spacecraft("Vostok 1", 1961);
    sp[1] = new Spacecraft("Apollo 11", 1969);
    sp[2] = new Spacecraft("ISS", 1998);
    sp[3] = new Spacecraft("SpaceX Dragon", 2012);
    sp[4] = new Spacecraft("Hubble telescope", 1990);
    sp[5] = new Spacecraft("Voyager 1", 1977);

    std::ofstream ofs("data.space");
    for (unsigned i = 0; i < 6; ++i)
        sp[i]->writeToBin(ofs);
    ofs.close();

    std::ifstream ifs("data.space");
    for (unsigned i = 0; i < 6; ++i)
        sp[i]->readFromBin(ifs);
    ifs.close();

    for (unsigned i = 0; i < 6; ++i)
    {
        std::cout << *sp[i];
        delete sp[i];
    }

    return 0;
}