#include <iostream>
#include <fstream>
#include "University.hpp"

int main()
{
    University uni;
    Student s("Ivan", "2MI0800034", 5.23, 1);
    uni += s;
    s = Student("Gosho", "3MI0500012", 4.67, 4);
    uni += s;
    s = Student("Petko", "0MI0800036", 3.99, 7);
    uni += s;
    std::ofstream ofs("data.txt", std::ios::out);
    ofs << uni;
    ofs.close();
    std::ifstream ifs("data.txt", std::ios::in);
    ifs>>uni;
    

    return 0;
}
