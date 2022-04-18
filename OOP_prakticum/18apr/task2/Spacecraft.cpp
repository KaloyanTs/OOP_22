#include "Spacecraft.hpp"

Spacecraft::Spacecraft(const char *_name, unsigned _year)
    : name(new char[strlen(_name) + 1]), launchYear(_year)
{
    strcpy(name, _name);
}

void Spacecraft::copy(const Spacecraft &other)
{
    clear();
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    launchYear = other.launchYear;
}

void Spacecraft::clear()
{
    delete[] name;
}

Spacecraft::Spacecraft(const Spacecraft &other)
    : name(nullptr)
{
    copy(other);
}

Spacecraft &Spacecraft::operator=(const Spacecraft &other)
{
    if (this != &other)
        copy(other);
    return *this;
}

Spacecraft::~Spacecraft()
{
    clear();
}

void Spacecraft::writeToBin(std::ofstream &ofs)
{
    size_t length = strlen(name);
    ofs.write((const char *)&length, sizeof(length));
    ofs.write(name, length);
    ofs.write((const char *)&launchYear, sizeof(launchYear));
}

void Spacecraft::readFromBin(std::ifstream &ifs)
{
    clear();
    size_t length;
    ifs.read((char *)&length, sizeof(length));
    name = new char[length + 1];
    ifs.read(name, length);
    name[length] = '\0';
    ifs.read((char *)&launchYear, sizeof(launchYear));
}

std::ostream &operator<<(std::ostream &ofs, const Spacecraft &Sp)
{
    return ofs << Sp.name << ';' << Sp.launchYear << '\n';
}