#include <iostream>
#include "Team.hpp"

int main()
{
    Team RM(std::cin);
    std::cout << RM;
    Team PSG(std::cin);
    std::cout << game(RM, PSG);
    std::cout << RM + PSG;
    Player a(4, 5);
    std::cout << ++a << a++;
    return 0;
}