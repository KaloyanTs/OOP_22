#ifndef __LIST_HPP
#define __LIST_HPP
#include <iostream>
#include <fstream>
#include <cassert>
const size_t INIT_CAPACITY = 2;

template <typename T>
class List
{
    T **arr;
    size_t size, capacity;

    void copy(const List<T> &other);

    void expand();

    void clear();

    bool isInList(const T &el) const;

public:
    List(size_t cap = INIT_CAPACITY);
    List(const List<T> &other);
    List<T> &operator=(const List<T> &other);
    ~List();

    List<T> &add(const T &el);

    List<T> &removeAt(unsigned index);

    List<T> &print();

    T &operator[](unsigned index);

    size_t getSize() const { return size; }

    bool isEmpty() const { return !size; }

    template <typename P>
    friend std::ofstream &operator<<(std::ofstream &ofs, const List<P> &L);

    template <typename P>
    friend std::ifstream &operator>>(std::ifstream &ifs, List<P> &L);
};

template <typename T>
void List<T>::clear()
{
    for (unsigned i = 0; i < size; ++i)
        delete arr[i];
    delete[] arr;
}

template <typename T>
List<T>::~List()
{
    clear();
}

template <typename T>
List<T>::List(size_t cap)
    : arr(new T *[cap]), capacity(cap), size(0)
{
}

template <typename T>
T &List<T>::operator[](unsigned index)
{
    assert(index < size);
    return arr[index];
}

template <typename T>
List<T> &List<T>::operator=(const List<T> &other)
{
    if (this != &other)
        copy(other);
    return *this;
}

template <typename T>
List<T> &List<T>::removeAt(unsigned index)
{
    assert(index < size);
    delete arr[index];
    --size;
    while (index < size)
    {
        arr[index] = arr[index + 1];
        ++index;
    }
    return *this;
}

template <typename T>
bool List<T>::isInList(const T &el) const
{
    unsigned i = 0;
    while (i < size && !(*arr[i] == el))
        ++i;
    return i < size;
}

template <typename T>
List<T> &List<T>::add(const T &el)
{
    if (isInList(el))
        return *this;
    if (size == capacity)
        expand();
    arr[size++] = new T(el);
    return *this;
}

template <typename T>
void List<T>::expand()
{
    capacity *= 2;
    T **newArr = new T *[capacity];
    for (unsigned i = 0; i < size; ++i)
        newArr[i] = arr[i];
    delete[] arr;
    arr = newArr;
}

template <typename T>
std::ofstream &operator<<(std::ofstream &ofs, const List<T> &L)
{
    ofs << L.size << '\n';
    for (unsigned i = 0; i < L.size; ++i)
        ofs << *L.arr[i] << '\n';
    return ofs;
}

template <typename T>
std::ifstream &operator>>(std::ifstream &ifs, List<T> &L)
{
    L.clear();
    ifs >> L.size;
    L.capacity = L.size;
    L.arr = new T *[L.capacity];
    for (unsigned i = 0; i < L.size; ++i)
    {
        L.arr[i] = new T;
        ifs >> *L.arr[i];
    }
    return ifs;
}

template <typename T>
List<T> &List<T>::print()
{
    for (unsigned i = 0; i < size; ++i)
        std::cout << i + 1 << ": " << *arr[i] << '\n';
    return *this;
}

template <typename T>
void List<T>::copy(const List<T> &other)
{
    clear();
    size = other.size;
    capacity = other.capacity;
    arr = new T *[capacity];
    for (unsigned i = 0; i < size; ++i)
        arr[i] = new T(*other.arr[i]);
}

#endif