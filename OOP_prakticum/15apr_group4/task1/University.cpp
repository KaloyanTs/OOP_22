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

void sort(bool (*less)(const Student &, const Student &))
{
    unsigned iMin;
    for (unsigned i = 0; i < size - 1; ++i)
    {
        iMin = 0;
        for (unsigned j = i + 1; j < size; ++j)
            if (less(students[j], students[iMin]))
                iMin = j;
        Student *tmp = arr[iMin];
        arr[iMin] = arr[i];
        arr[i] = tmp;
    }
}