#include "Student.hpp"

std::ostream &operator<<(std::ostream &out, const Student &S)
{
    return out << S.name << '\t' << S.age << '\n';
}

std::istream &operator>>(std::istream &in, Student &S)
{
    in.getline(S.name, NAME_MAX);
    return in >> S.age;
}