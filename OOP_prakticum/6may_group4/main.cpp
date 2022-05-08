#include <iostream>
#include "List.hpp"

int main()
{
    List<double> L;
    L.add(2.45).add(2.46).add(3.98).add(4.234).add(6).removeAt(1).print();
    std::ofstream ofs("int.arr", std::ios::out);
    if (!ofs.is_open())
        return 1;
    ofs << L;
    ofs.close();
    L = List<double>(4);
    L.print();
    std::ifstream ifs("int arr", std::ios::in);
    if (!ifs.is_open())
        return 1;
    ifs >> L;
    ifs.close();
    L.print();
    return 0;
}