#include "Specialty.hpp"

Specialty::Specialty()
{
    name = nullptr;
    studentCount = 0;
    studentCapacity = INIT_CAPACITY;
    students = new (std::nothrow) const Student *[INIT_CAPACITY];
    if (!students)
    {
        studentCapacity = 0;
        return;
    }
    std::cout << "<Specialty created succeessfully.>\n";
}

Specialty::Specialty(const char *_name)
{
    name = new (std::nothrow) char[strlen(_name) + 1];
    if (name)
        strcpy(name, _name);
    else
        std::cout << "<Failed to set name of Specialty>\n";
    studentCount = 0;
    studentCapacity = INIT_CAPACITY;
    students = new (std::nothrow) const Student *[INIT_CAPACITY];
    if (!students)
    {
        studentCapacity = 0;
        return;
    }
    std::cout << "<Specialty created succeessfully.>\n";
}

Specialty::Specialty(const Specialty &S)
{
    name = nullptr;
    students = nullptr;
    copy(S);
    std::cout << "<Specialty created succeessfully.>\n";
}

void Specialty::addStudent(Student *Sptr)
{
    if (!Sptr || Sptr->getSpecialty() != this)
        return;
    if (studentCount < studentCapacity)
    {
        students[studentCount++] = Sptr;
        return;
    }
    const Student **newArr = new (std::nothrow) const Student *[(studentCapacity ? 2 * studentCapacity : INIT_CAPACITY)];
    if (!newArr)
    {
        std::cout << "<Adding Student failed.>\n";
        return;
    }
    for (unsigned i = 0; i < studentCount; ++i)
        newArr[i] = students[i];
    newArr[studentCount++] = Sptr;
    if (studentCapacity)
        studentCapacity <<= 1;
    delete[] students;
    students = newArr;
    std::cout << "<Student added successfully.>\n";
}

const Specialty &Specialty::operator=(const Specialty &S)
{
    if (this != &S)
        copy(S);
    return *this;
}

void Specialty::print() const
{
    std::cout << "Name: " << (name ? name : " - ") << "\nStudents:\n";
    for (unsigned i = 0; i < studentCount; ++i)
    {
        std::cout << '\t' << i + 1 << ": ";
        students[i]->print();
    }
}

Specialty::~Specialty()
{
    if (name)
        delete[] name;
    if (students)
        delete[] students;
    std::cout << "<Specialty deleted successfully.>\n";
}

void Specialty::setName(const char *_name)
{
    char *newName = new (std::nothrow) char[strlen(_name) + 1];
    if (!newName)
    {
        std::cout << "<Specialty could not be modified.>\n";
        return;
    }
    strcpy(newName, _name);
    if (name)
        delete[] name;
    name = newName;
    std::cout << "<Specialty modified successfully.>\n";
}

void Specialty::copy(const Specialty &S)
{
    char *newName = new (std::nothrow) char[strlen(S.name) + 1];
    if (!newName)
    {
        std::cout << "<Specialty could not be copied.>\n";
        return;
    }
    const Student **newArr = new (std::nothrow) const Student *[S.studentCapacity];
    if (!newArr)
    {
        delete[] newName;
        std::cout << "<Specialty could not be copied.>\n";
        return;
    }
    if (name)
        delete[] name;
    if (students)
        delete[] students;
    strcpy(newName, S.name);
    for (unsigned i = 0; i < S.studentCount; ++i)
        newArr[i] = S.students[i];
    studentCapacity = S.studentCapacity;
    studentCount = S.studentCount;
    std::cout << "<Specialty copied successfully.>\n";
}
