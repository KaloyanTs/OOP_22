#include <iostream>
#include <cstring>
#include "NightClub.hpp"
const unsigned BUF_MAX = 16;

bool executeCMD(NightClub &nC, const char *cmd)
{
    if (!strcmp(cmd, "e"))
        return false;
    if (!strcmp(cmd, "aa"))
    {
        nC.addAlcohol();
        return true;
    }
    else if (!strcmp(cmd, "ab"))
    {
        nC.addBalloon();
        return true;
    }
    else if (!strcmp(cmd, "as"))
    {
        nC.addShisha();
        return true;
    }
    else if (!strcmp(cmd, "rb"))
    {
        char color[BUF_MAX];
        std::cout << "Enter color of balloon to be removed: ";
        std::cin.getline(color, BUF_MAX);
        nC.removeBalloon(color);
        return true;
    }
    else if (!strcmp(cmd, "rs"))
    {
        char brand[BUF_MAX];
        std::cout << "Enter brand of shisha to be removed: ";
        std::cin.getline(brand, BUF_MAX);
        char taste[BUF_MAX];
        std::cout << "Enter taste of shisha to be removed: ";
        std::cin.getline(taste, BUF_MAX);
        nC.removeShisha(brand, taste);
        return true;
    }
    else if (!strcmp(cmd, "ra"))
    {
        char name[BUF_MAX];
        std::cout << "Enter name of alcohol to be removed: ";
        std::cin.getline(name, BUF_MAX);
        nC.removeAlcohol(name);
        return true;
    }
    else if (!strcmp(cmd, "cb"))
    {
        Balloon buf;
        buf.read();
        std::cout << "Balloon was ";
        if (!nC.checkBalloon(buf))
            std::cout << "NOT ";
        std::cout << "found.\n";
        return true;
    }
    else if (!strcmp(cmd, "cs"))
    {
        Shisha buf;
        buf.read();
        std::cout << "Shisha was ";
        if (!nC.checkShisha(buf))
            std::cout << "NOT ";
        std::cout << "found.\n";
        return true;
    }
    else if (!strcmp(cmd, "ca"))
    {
        Alcohol buf;
        buf.read();
        std::cout << "Alcohol was ";
        if (!nC.checkAlcohol(buf))
            std::cout << "NOT ";
        std::cout << "found.\n";
        return true;
    }
    else if (!strcmp(cmd, "pr"))
    {
        nC.print();
        return true;
    }

    std::cout << "<Invalid command.>\n";
    return true;
}

int main()
{
    NightClub Plazza;
    char cmd[BUF_MAX];
    do
    {
        std::cout << "Enter command: ";
        std::cin.getline(cmd, BUF_MAX);
    } while (executeCMD(Plazza, cmd));
    return 0;
}