#include "Subject.hpp"

Subject::Subject()
{
    name = lecturerName = nullptr;
    specialty = nullptr;
    credits = 0;
    std::cout << "<Subject created successfully.>\n";
}

Subject::Subject(const char *_name, const char *lName, unsigned _credits,
                 const char *spName, Specialty **list, size_t listSize)
{
    name = lecturerName = nullptr;
    specialty = nullptr;
    name = new (std::nothrow) char[strlen(_name) + 1];
    if (!name)
        return;
    strcpy(name, _name);
    lecturerName = new (std::nothrow) char[strlen(lName) + 1];
    if (!lecturerName)
    {
        delete[] name;
        name = nullptr;
        return;
    }
    strcpy(lecturerName, lName);
    credits = _credits;
    unsigned i = 0;
    while (i < listSize && strcmp(spName, list[i]->getName()))
        ++i;
    if (i < listSize)
        specialty = list[i];
    std::cout << "<Subject created successfully.>\n";
}

void Subject::copy(const Subject &S)
{
    char *newName = new (std::nothrow) char[strlen(S.name) + 1];
    if (!newName)
    {
        std::cout << "<Subject could not be copied.>\n";
        return;
    }
    char *newLName = new (std::nothrow) char[strlen(S.lecturerName) + 1];
    if (!newLName)
    {
        std::cout << "<Subject could not be copied.>\n";
        return;
    }
    strcpy(newName, S.name);
    strcpy(newLName, S.lecturerName);
    if (name)
        delete[] name;
    if (lecturerName)
        delete[] lecturerName;
    name = newName;
    lecturerName = newLName;
    specialty = S.specialty;
    credits = S.credits;
}

Subject::Subject(const Subject &S)
{
    name = lecturerName = nullptr;
    specialty = nullptr;
    credits = 0;
    copy(S);
    std::cout << "<Subject created successfully.>\n";
}

const Subject &Subject::operator=(const Subject &S)
{
    if (this != &S)
        copy(S);
    return *this;
}

Subject::~Subject()
{
    if (name)
        delete[] name;
    if (lecturerName)
        delete[] lecturerName;
    std::cout << "<Subject deleted successfully.>\n";
}

void Subject::print() const
{
    const char *spName = (specialty ? specialty->getName() : nullptr);
    std::cout << "Subject name: " << (name ? name : " - ")
              << "\tLecturer Name: " << (lecturerName ? lecturerName : " - ")
              << "\tStudied in specialty: " << (spName ? spName : " - ")
              << "\tCredits: " << credits << '\n';
}

void Subject::read(Specialty **list, size_t listSize)
{
    char buf[INPUT_MAX];
    std::cout << "Enter subject's name: ";
    std::cin.getline(buf, INPUT_MAX);
    char *newName = new (std::nothrow) char[strlen(buf) + 1];
    if (!newName)
    {
        std::cout << "<Subject could not be read.>\n";
        return;
    }
    strcpy(newName, buf);
    std::cout << "Enter lecturer's name: ";
    std::cin.getline(buf, INPUT_MAX);
    char *newLName = new (std::nothrow) char[strlen(buf) + 1];
    if (!newLName)
    {
        delete[] newName;
        std::cout << "<Subject could not be read.>\n";
        return;
    }
    strcpy(newLName, buf);
    std::cout << "Enter specialty where subject is taught: ";
    std::cin.getline(buf, INPUT_MAX);
    unsigned i = 0;
    while (i < listSize && strcmp(buf, list[i]->getName()))
        ++i;
    if (i < listSize)
        specialty = list[i];
    else
        specialty = nullptr;
    if (name)
        delete[] name;
    if (lecturerName)
        delete[] lecturerName;
    name = newName;
    lecturerName = newLName;
    std::cout << "Enter credits given by the subject: ";
    std::cin >> credits;
    std::cout << "<Subject read successfully.>\n";
}
