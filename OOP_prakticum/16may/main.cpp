#include <iostream>
#include "General.hpp"

int main()
{

    Soldier<int> arr[3] =
        {
            Soldier<int>(),
            Soldier<int>("dsfs", 54),
            Soldier<int>("dsfdfss", 21, 600, 700)};
    Commander<int> ti("dsfs", 34, 89, 9000, "dfsddsfsdfsdfsd\nfdsfss");
    Soldier<int> *ptr[4] =
        {
            &ti,
            &arr[1],
            &arr[2],
            &arr[0]};

    ti.addToArmy(arr[1]).addToArmy(arr[2]).addToArmy(arr[0]);

    for (unsigned i = 0; i < 4; ++i)
        std::cout << *ptr[i] << '\n';

    Commander<int> cArr[3] =
        {
            Commander<int>(),
            Commander<int>("dsfs", 54),
            Commander<int>("dsfdfss", 21, 600, 700)};

    cArr[0].addToArmy(Soldier<int>("dfdds",89,99)).addToArmy(Soldier<int>("dfdds"));
    cArr[1].addToArmy(Soldier<int>("dfddsfsdfsfss")).addToArmy(Soldier<int>("dfdds"));
    cArr[2].addToArmy(Soldier<int>("werds"));

    General<int> az("dsfs", 34, 89, 9000, "dfsddsfsdfsdfsd\nfdsfss");
    Soldier<int> *ptrGen[4] =
        {
            &az,
            &cArr[1],
            &cArr[2],
            &cArr[0]};

    az.addToArmy(cArr[1]).addToArmy(cArr[2]).addToArmy(cArr[0]);

    for (unsigned i = 0; i < 4; ++i)
        std::cout << *ptrGen[i] << '\n';

    std::cout << az.averagePower() << '\n';

    return 0;
}