#ifndef __PERSON_HPP
#define __PERSON_HPP
#include <iostream>
#include <cstring>

class Person
{
    char *name;
    unsigned age;

    void clear();
    void copy(const Person &other);

public:
    Person(const char *_name = "no name", unsigned age = 0);
    Person(const Person &other);
    Person &operator=(const Person &other);
    ~Person();

    const char *getName() const { return name; }
    unsigned getAge() const { return age; }

    virtual void print(std::ostream &os)const;
};

std::ostream &operator<<(std::ostream &os, const Person &P);

#endif