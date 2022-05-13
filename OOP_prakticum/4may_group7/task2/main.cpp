#include <iostream>
#include "Worker.hpp"
#include "Company.hpp"

int main()
{
    Worker w("Ivan", 27, 2000);
    std::cout << w << '\n';
    w = Worker("dsf", 3, 23);
    std::cout << w << '\n';

    Company cmp;
    Worker arr[5] = {Worker("Ivan", 27, 2000),
                     Worker("Gosho", 43, 3400),
                     Worker("Petko", 20, 1400),
                     Worker("Vlado", 34, 2879),
                     Worker("Svetlio", 54, 100000)};
    for (unsigned i = 0; i < 5; ++i)
        cmp.addWorker(arr[i]);
    std::cout << cmp;
    std::cout<<std::boolalpha<<cmp.isInCompany("Ivan")<<'\n';
    std::cout<<std::boolalpha<<cmp.isInCompany("Az")<<'\n';
    cmp.showWorkerInfo("Petko");
    return 0;
}