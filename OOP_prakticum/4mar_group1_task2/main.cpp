#include <iostream>
#include <cstring>
#include "Sector.hpp"

bool executeCmd(Sector &s, const char *cmd)
{
    if (!strcmp(cmd, "exit"))
        return false;
    else if (!strcmp(cmd, "print"))
        s.print();
    else if (!strcmp(cmd, "acquire"))
    {
        char buyer[NAME_MAX], bought[NAME_MAX];
        std::cout << "Enter names of buyer company and acquired company:\n";
        std::cin.getline(buyer, NAME_MAX);
        std::cin.getline(bought, NAME_MAX);
        s.acquire(buyer, bought);
    }
    return true;
}

int main()
{
    char cmd[NAME_MAX] = "";
    Sector s;
    s.readSector();
    do
    {
        std::cout << "> ";
        std::cin.getline(cmd, NAME_MAX);
    } while (executeCmd(s, cmd));
    return 0;
}