#include "Pet.hpp"

Pet::Pet(const char *name, unsigned age,
         const char *_owner, unsigned _phone)
    : Animal(name, age), owner(new char[strlen(_owner) + 1]), phone(_phone)
{
    strcpy(owner, _owner);
}

Pet::Pet(const Pet &other)
    : Animal(*(Animal *)&other), owner(nullptr)
{
    Animal::copy(other);
    copy(other);
}

Pet &Pet::operator=(const Pet &other)
{
    if (this != &other)
    {
        Animal::copy(other);
        copy(other);
    }
    return *this;
}

Pet::~Pet()
{
    clear();
}

void Pet::setOwner(const char *_owner)
{
    delete[] owner;
    owner = new char[strlen(_owner) + 1];
    strcpy(owner, _owner);
}

std::ostream &operator<<(std::ostream &os, const Pet &P)
{
    // todo try different implementations
    return os << *(Animal *)&P
              << "\nOwner: " << P.getOwner()
              << "\tPhone Number: " << P.getPhoneNumber();
}

void Pet::clear()
{
    delete[] owner;
}

void Pet::copy(const Pet &other)
{
    clear();
    owner = new char[strlen(other.owner) + 1];
    strcpy(owner, other.owner);
    phone = other.phone;
}