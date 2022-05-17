#ifndef __GENERAL_HPP
#define __GENERAL_HPP
#include "Commander.hpp"

template <typename T>
class General : public Soldier<T>
{
    static const unsigned INIT_CAPACITY = 2;
    char *description;
    Commander<T> **army;
    size_t size, capacity;

    void clear();
    void expand();
    void copy(const General<T> &other);

public:
    General(const char *name = "anonymous", unsigned age = 0,
            T skills = T(), unsigned salary = 0,
            const char *desc = "none.")
        : Soldier<T>(name, age, skills, salary),
          description(new char[strlen(desc) + 1]),
          size(0), capacity(INIT_CAPACITY),
          army(new Commander<T> *[INIT_CAPACITY])
    {
        strcpy(description, desc);
    }
    General(const General<T> &other);
    General &operator=(const General<T> &other);
    ~General();

    General<T> &addToArmy(const Commander<T> &S);

    void print(std::ostream &os = std::cout) const;

    T averagePower() const;
};

template <typename T>
General<T>::General(const General<T> &other)
    : Soldier<T>(other), description(nullptr)
{
    copy(other);
}

template <typename T>
General<T> &General<T>::operator=(const General<T> &other)
{
    if (this != &other)
    {
        Soldier<T>::copy(other);
        copy(other);
    }
    return *this;
}

template <typename T>
General<T>::~General()
{
    clear();
}

template <typename T>
void General<T>::print(std::ostream &os) const
{
    Soldier<T>::print(os);
    os << "\nHis army: " << description << '\n';
    if (size)
        os << "List of the Commanders in the army:\n";
    for (unsigned i = 0; i < size; ++i)
        std::cout << i + 1 << ": " << *army[i] << '\n';
}

template <typename T>
void General<T>::clear()
{
    delete[] description;
    for (unsigned i = 0; i < size; ++i)
        delete army[i];
    delete[] army;
}

template <typename T>
void General<T>::expand()
{
    capacity <<= 1;
    Commander<T> **newArr = new Commander<T> *[capacity];
    for (unsigned i = 0; i < size; ++i)
        newArr[i] = army[i];
    delete[] army;
    army = newArr;
}

template <typename T>
void General<T>::copy(const General<T> &other)
{
    Commander<T>::copy(other);
    clear();
    description = new char[strlen(other.description) + 1];
    strcpy(description, description);
    size = other.size;
    capacity = other.capacity;
    army = new Commander<T> *[capacity];
    for (unsigned i = 0; i < size; ++i)
        army[i] = new Commander<T>(*other.army[i]);
}

template <typename T>
General<T> &General<T>::addToArmy(const Commander<T> &S)
{
    if (size == capacity)
        expand();
    army[size++] = new Commander<T>(S);
    return *this;
}

template <typename T>
T General<T>::averagePower() const
{
    T sum = T();
    unsigned soldierCount = 0;
    for (unsigned i = 0; i < size; ++i)
    {
        sum += army[i]->getTotalSkill();
        soldierCount += army[i]->getArmyCount();
    }
    return (soldierCount ? sum / soldierCount : 0);
}

#endif