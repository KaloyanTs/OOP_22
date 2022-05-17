#ifndef __SOLDIER_HPP
#define __SOLDIER_HPP
#include <iostream>
#include <cstring>

template <typename T>
class Soldier
{
    char *name;
    unsigned age;
    T skills;
    unsigned salary;

    void clear();

protected:
    void copy(const Soldier<T> &other);

public:
    Soldier(const char *n = "anonymous", unsigned age = 0,
            T sk = T(), unsigned s = 0);
    Soldier(const Soldier<T> &other);
    Soldier &operator=(const Soldier<T> &other);
    ~Soldier();
    unsigned getSalary() const { return salary; }
    T getSkills() const { return skills; }
    virtual void print(std::ostream &os = std::cout) const;
};

template <typename T>
void Soldier<T>::clear()
{
    delete[] name;
}

template <typename T>
void Soldier<T>::copy(const Soldier<T> &other)
{
    clear();
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    skills = other.skills;
    salary = other.salary;
    age = other.age;
}

template <typename T>
Soldier<T>::Soldier(const Soldier<T> &other)
    : name(nullptr)
{
    copy(other);
}

template <typename T>
Soldier<T> &Soldier<T>::operator=(const Soldier<T> &other)
{
    if (this != &other)
        copy(other);
    return *this;
}

template <typename T>
Soldier<T>::~Soldier()
{
    clear();
}

template <typename T>
Soldier<T>::Soldier(const char *n,
                    unsigned a,
                    T sk, unsigned s)
    : name(new char[strlen(n) + 1]),
      age(a),
      skills(sk),
      salary(s)
{
    strcpy(name, n);
}

template <typename T>
void Soldier<T>::print(std::ostream &os) const
{
    os << name << ", " << age
       << " has skills " << skills
       << " and salary " << salary;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Soldier<T> &S)
{
    S.print(os);
    return os;
}

#endif