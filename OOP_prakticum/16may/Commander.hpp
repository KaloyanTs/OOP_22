#ifndef __COMMANDER_HPP
#define __COMMANDER_HPP
#include "Soldier.hpp"

template <typename T>
class Commander : public Soldier<T>
{
    static const unsigned INIT_CAPACITY = 2;
    char *description;
    Soldier<T> **army;
    size_t size, capacity;

    void clear();
    void expand();
    void copy(const Commander<T> &other);

public:
    Commander(const char *name = "anonymous", unsigned age = 0,
              T skills = T(), unsigned salary = 0,
              const char *desc = "none.")
        : Soldier<T>(name, age, skills, salary),
          description(new char[strlen(desc) + 1]),
          size(0), capacity(INIT_CAPACITY),
          army(new Soldier<T> *[INIT_CAPACITY])
    {
        strcpy(description, desc);
    }
    Commander(const Commander<T> &other);
    Commander &operator=(const Commander<T> &other);
    ~Commander();

    Commander<T> &addToArmy(const Soldier<T> &S);

    void print(std::ostream &os = std::cout) const;

    T getTotalSkill() const;
    unsigned getArmyCount() const { return size; }
    T averagePower() const { return (size ? getTotalSkill() / size : 0); }
};

template <typename T>
Commander<T>::Commander(const Commander<T> &other)
    : Soldier<T>(other), description(nullptr), army(nullptr), size(0)
{
    copy(other);
}

template <typename T>
Commander<T> &Commander<T>::operator=(const Commander<T> &other)
{
    if (this != &other)
    {
        Soldier<T>::copy(other);
        copy(other);
    }
    return *this;
}

template <typename T>
Commander<T>::~Commander()
{
    clear();
}

template <typename T>
void Commander<T>::print(std::ostream &os) const
{
    Soldier<T>::print(os);
    os << "\nHis army: " << description << '\n';
    if (size)
        os << "List of the soldiers in the army:\n";
    for (unsigned i = 0; i < size; ++i)
        std::cout << i + 1 << ": " << *army[i] << '\n';
}

template <typename T>
void Commander<T>::clear()
{
    delete[] description;
    for (unsigned i = 0; i < size; ++i)
        delete army[i];
    delete[] army;
}

template <typename T>
void Commander<T>::expand()
{
    capacity <<= 1;
    Soldier<T> **newArr = new Soldier<T> *[capacity];
    for (unsigned i = 0; i < size; ++i)
        newArr[i] = army[i];
    delete[] army;
    army = newArr;
}

template <typename T>
void Commander<T>::copy(const Commander<T> &other)
{
    clear();
    description = new char[strlen(other.description) + 1];
    strcpy(description, description);
    size = other.size;
    capacity = other.capacity;
    army = new Soldier<T> *[capacity];
    for (unsigned i = 0; i < size; ++i)
        army[i] = new Soldier<T>(*other.army[i]);
}

template <typename T>
Commander<T> &Commander<T>::addToArmy(const Soldier<T> &S)
{
    if (size == capacity)
        expand();
    army[size++] = new Soldier<T>(S);
    return *this;
}

template <typename T>
T Commander<T>::getTotalSkill() const
{
    T res = T();
    for (unsigned i = 0; i < size; ++i)
        res += army[i]->getSkills();
    return res;
}

#endif