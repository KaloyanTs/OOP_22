#ifndef __RELATION_HPP
#define __RELATION_HPP
#include <iostream>
#include <cstring>

template <typename T>
class Relation
{
    T subject, object;
    char *relation;

    void clear();
    void copy(const Relation &other);
    static unsigned digitCount(int n);

public:
    Relation(const T &sub = T(), const T &obj = T(),
             const char *rel = "exists, such as");
    Relation(const Relation &other);
    Relation &operator=(const Relation &other);
    ~Relation();

    void print() const;

    Relation<T> operator*(const Relation<T> &other) const;
};

template <typename T>
Relation<T>::Relation(const T &sub, const T &obj,
                      const char *rel)
    : relation(new char[strlen(rel) + 1]),
      subject(sub), object(obj)
{
    strcpy(relation, rel);
}

template <typename T>
Relation<T>::Relation(const Relation &other)
    : relation(new char[strlen(other.relation) + 1]),
      subject(other.subject),
      object(other.object)
{
    strcpy(relation, other.relation);
}

template <typename T>
Relation<T> &Relation<T>::operator=(const Relation<T> &other)
{
    if (this != &other)
    {
        delete[] relation;
        relation = new char[strlen(other.relation) + 1];
        strcpy(relation, other.relation);
        subject = other.subject;
        object = other.object;
    }
    return *this;
}

template <typename T>
Relation<T>::~Relation()
{
    delete[] relation;
}

template <typename T>
void Relation<T>::print() const
{
    std::cout << subject << ' ' << relation << ' ' << object;
}

template <typename T>
Relation<T> Relation<T>::operator*(const Relation<T> &other) const
{
    if (!(object == other.subject))
        return *this;
    char *newRelation = new char[strlen(relation) + 1 +
                                 digitCount((int)object) +
                                 strlen(", which is ") +
                                 strlen(other.relation) + 1];
    strcpy(newRelation, relation);
    strcat(newRelation, " ");
    itoa((int)object, newRelation + strlen(relation) + 1, 10);
    strcat(newRelation, ", which is ");
    strcat(newRelation, other.relation);
    Relation<T> res(subject, other.object, newRelation);
    delete[] newRelation;
    return res;
}

template <typename T>
unsigned Relation<T>::digitCount(int n)
{
    unsigned res = 0;
    do
    {
        ++res;
        n /= 10;
    } while (n);
    return res;
}

#endif