#ifndef __PET_HPP
#define __PET_HPP
#include "Animal.hpp"

class Pet : public Animal
{
    char *owner;
    unsigned phone;

    void clear();
    void copy(const Pet &other);

public:
    Pet(const char *name = "unknown", unsigned age = 0,
        const char *_owner = "unknown", unsigned _phone = 0);
    Pet(const Pet &other);
    Pet &operator=(const Pet &other);
    ~Pet();

    const char *getOwner() const { return owner; }
    unsigned getPhoneNumber() const { return phone; }

    void setOwner(const char *_owner);
};

std::ostream &operator<<(std::ostream &os, const Pet &P);

#endif