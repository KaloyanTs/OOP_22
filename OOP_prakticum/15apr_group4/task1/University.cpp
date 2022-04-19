#include "University.hpp"

void University::copy(const University &other)
{
    clear();
    capacity = other.capacity;
    size = other.size;
    students = new Student *[other.capacity];
    for (unsigned i = 0; i < size; ++i)
        students[i] = new Student(*other.students[i]);
}

void University::resize(unsigned newCap)
{
    if (newCap <= capacity)
        return;

    capacity = newCap;
    Student **newArr = new Student *[capacity];
    for (unsigned i = 0; i < size; ++i)
        newArr[i] = students[i];
    delete[] students;
    students = newArr;
}

void University::clear()
{
    for (unsigned i = 0; i < size; ++i)
        delete students[i];
    delete[] students;
}

University::University(const University &other)
    : students(nullptr)
{
    copy(other);
}

University::~University()
{
    clear();
}

void University::sort(bool (*less)(const Student &, const Student &))
{
    unsigned iMin;
    for (unsigned i = 0; i < size - 1; ++i)
    {
        iMin = 0;
        for (unsigned j = i + 1; j < size; ++j)
            if (less(*students[j], *students[iMin]))
                iMin = j;
        Student *tmp = students[iMin];
        students[iMin] = students[i];
        students[i] = tmp;
    }
}

std::ofstream &operator<<(std::ofstream &os, const University &U)
{
    os << U.size;
    os << '\n';
    for (unsigned i = 0; i < U.size; ++i)
        os << *U.students[i];
    return os;
}

std::ifstream &operator>>(std::ifstream &is, University &U)
{
    U.clear();
    is >> U.size;
    U.capacity = U.size;
    U.students = new Student *[U.size];
    for (unsigned i = 0; i < U.size; ++i)
    {
        U.students[i] = new Student;
        is >> *U.students[i];
    }
    return is;
}

void University::filter(bool (*pred)(const Student &))
{
    for (unsigned i = 0; i < size; ++i)
        if (pred(*students[i]))
            std::cout << students[i];
}

University &University::operator+=(const Student &st)
{
    unsigned i = 0;
    while (i < size && strcmp(st.getFN(), students[i]->getFN()))
        ++i;
    if (i < size)
        return *this;
    if (size == capacity)
        resize(2 * capacity);
    students[size++] = new Student(st);
    return *this;
}
University &University::operator-=(const char *fn)
{
    unsigned i = 0;
    while (i < size && strcmp(fn, students[i]->getFN()))
        ++i;
    if (i == size)
        return *this;
    delete students[i];
    while (i < size - 1)
    {
        students[i] = students[i + 1];
        ++i;
    }
    --size;
    return *this;
}

Student University::operator[](unsigned index) const
{
    assert(index < size);
    return *students[index];
}

University::University(size_t cap)
    : students(new Student *[cap]), size(0), capacity(cap)
{
}