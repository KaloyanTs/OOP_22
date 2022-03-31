#include <iostream>
#include "Auto.hpp"

int main()
{
    Auto a("ST4142AN", "Volvo", 2002, "YT");
    std::cout << a;
    std::cin >> a;
    std::cout << a;
    return 0;
}