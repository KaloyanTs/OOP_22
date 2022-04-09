#include <iostream>
#include "University.hpp"

void seeUniversities()
{
    std::ifstream in;
    in.open("universities.txt");
    assert(in.is_open());
    size_t size = in.seekg(0, std::ios::end).tellg();
    ++size;
    in.seekg(0, std::ios::beg);
    char *info = new (std::nothrow) char[size];
    assert(info);
    in.read(info, size);
    info[size - 1] = '\0';
    std::cout << info << '\n';
    in.close();
}

int main()
{
    University su("su");
    std::cout << su << '\n';
    Student n;
    std::cin >> n;
    su.addStudent(n);
    su.write();
    seeUniversities();
    return 0;
}