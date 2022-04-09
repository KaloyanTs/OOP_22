#include "Animal.hpp"

Animal::Animal()
    : name(new (std::nothrow) char[1]),
      breed(new (std::nothrow) char[1]),
      owner(new (std::nothrow) char[1]),
      age(0)
{
    assert(name && breed && owner);
    *name = *breed = *owner = '\0';
}

Animal::Animal(const char *_n, const char *_b, const char *_o, unsigned _age)
    : name(new (std::nothrow) char[strlen(_n) + 1]),
      breed(new (std::nothrow) char[strlen(_b) + 1]),
      owner(new (std::nothrow) char[strlen(_o) + 1]),
      age(_age)
{
    assert(name && breed && owner);
    strcpy(name, _n);
    strcpy(breed, _b);
    strcpy(owner, _o);
}

void Animal::copy(const Animal &other)
{
    clear();
    name = new (std::nothrow) char[strlen(other.name) + 1];
    assert(name);
    breed = new (std::nothrow) char[strlen(other.breed) + 1];
    assert(breed);
    owner = new (std::nothrow) char[strlen(other.owner) + 1];
    assert(owner);
    strcpy(name, other.name);
    strcpy(breed, other.breed);
    strcpy(owner, other.owner);
    age = other.age;
}

void Animal::clear()
{
    delete[] name;
    delete[] breed;
    delete[] owner;
}

Animal::Animal(const Animal &other)
    : name(nullptr), breed(nullptr), owner(nullptr)
{
    copy(other);
}

Animal::~Animal()
{
    clear();
}

void Animal::writeBinary(const char *path) const
{
    std::ofstream out;
    out.open(path, std::ios::binary | std::ios::app);
    std::cout << out.is_open() << '\n';
    out << "Name: " << name
        << "\tBreed: " << breed
        << "\tOwner: " << owner
        << "\tAge: " << age << '\n';
    out.close();
}

void Animal::writeText(const char *path) const
{
    std::ofstream out;
    out.open(path, std::ios::app);
    out << "Name: " << name
        << "\tBreed: " << breed
        << "\tOwner: " << owner
        << "\tAge: " << age << '\n';
    out.close();
}

Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
        copy(other);
    return *this;
}
