#include <iostream>
#include "OfficeBuilding.hpp"

int main()
{
    ChillRoom r1("chill", true, 5, true, "Team #1");
    Office r2("of", true, "Az", 2);
    ConferenceRoom r3("dsfddfsd");
    OfficeBuilding a;
    a.addRoom(r1).addRoom(r2).addRoom(r3);
    a.showRooms().sortByCapacity();
    std::cout << '\n';
    a.showRooms();

    return 0;
}