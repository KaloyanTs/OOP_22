#include <iostream>
#include "Corporation.hpp"

int main()
{
    Employee a("Ivan", "3242", "boss", 3000);
    a.print();
    Employee b("Petko", "65746342", "boss", 3000);
    Employee c("Zhoro", "12", "pich", 3000);
    Employee d("Borkata", "23445", "portier", 3000);
    Employee e("Joni", "67456", "best of all", 3000);
    Employee f("Kris", "64632", "cleaner", 3000);
    Corporation big("Firmata", 4, 0);
    Corporation small1("Firmichkata1", 4, 0);
    Corporation small2("Firmichkata2", 3, 2);

    big.hire(a).hire(b).hire(d);
    big.print();
    small1.hire(c).hire(e);
    small1.print();
    small2.hire(f);
    small2.print();
    big.acquire(small1);
    big.print();
    small1.print();
    big.acquire(small2);
    small2.print();
    big.print();
    big.getEmployees().print();

    return 0;
}