#include "ConferenceRoom.hpp"

ConferenceRoom::ConferenceRoom(const char *name, bool free, unsigned cap, bool proj)
    : Room(name, free, cap), hasProjector(proj)
{
}

void ConferenceRoom::print() const
{
    Room::print();
    std::cout << " and ";
    if (!hasProjector)
        std::cout << "does not ";
    std::cout << "have a projector";
}