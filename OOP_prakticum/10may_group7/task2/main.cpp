#include <iostream>
#include "Manager.hpp"

int main()
{
    Manager az("K", 19, 8, 100, "firma");
    Manager ti("J", 20, 1, 300, "service");
    ti.addWorker(Worker("1111")).addWorker(Worker("2222", 43)).addWorker(Manager("3333", 65));
    std::cout << ti << '\n';
    az.addWorker(ti);
    std::cout << az << '\n';
    return 0;
}