#include "Student.hpp"

Student::Student()
{
    names = nullptr;
    fn = nullptr;
    namesCount = 0;
    specialty = nullptr;
    credits = 0;
    std::cout << "<Student created successfully.>\n";
}

void Student::copy(const Student &S)
{
    char *newFn = new (std::nothrow) char[strlen(S.fn) + 1];
    if (!newFn)
    {
        std::cout << "<Student copying failed.>\n";
        return;
    }
    strcpy(newFn, S.fn);
    char **newNames = new (std::nothrow) char *[S.namesCount];
    if (!newNames)
    {
        std::cout << "<Student copying failed.>\n";
        return;
    }
    for (unsigned i = 0; i < namesCount; ++i)
    {
        newNames[i] = new (std::nothrow) char[strlen(S.names[i]) + 1];
        if (!newNames[i])
        {
            dealloc(newNames, i);
            delete[] newFn;
            std::cout << "<Student copying failed.>\n";
            return;
        }
        strcpy(newNames[i], S.names[i]);
    }
    dealloc(names, namesCount);
    if (fn)
        delete[] fn;
    names = newNames;
    fn = newFn;
    namesCount = S.namesCount;
    credits = S.credits;
    specialty = S.specialty;
    std::cout << "<Student copied successfully.>\n";
}

void Student::dealloc(char **&arr, size_t count)
{
    for (unsigned i = 0; i < count; ++i)
        delete[] arr[i];
    delete[] arr;
    arr = nullptr;
}

Student::Student(const Student &S)
{
    names = nullptr;
    fn = nullptr;
    specialty = nullptr;
    copy(S);
    std::cout << "<Student created successfully.>\n";
}

const Student &Student::operator=(const Student &S)
{
    if (this != &S)
        copy(S);
    return *this;
}

void Student::print() const
{
    const char *spName = (specialty ? specialty->getName() : nullptr);
    std::cout << "Name: ";
    for (unsigned i = 0; i < namesCount; ++i)
        std::cout << names[i] << ' ';
    std::cout << "\tID: " << (fn ? fn : " - ")
              << "\tSpecialty: " << (spName ? spName : " - ")
              << "\tCredits: " << credits << '\n';
}

Student::~Student()
{
    dealloc(names, namesCount);
    std::cout << "<Student deleted successfully.>\n";
}

void Student::read(Specialty **spArr, size_t spCount)
{
    std::cout << "Enter student's name: ";
    char buf[INPUT_MAX];
    std::cin.getline(buf, INPUT_MAX);
    unsigned newNameCount = countNames(buf);
    char **newName = new (std::nothrow) char *[newNameCount];
    if (!newName)
    {
        std::cout << "<Student could not be read.>\n";
        return;
    }
    const char *bufNameBegin = buf, *bufNameEnd = buf;
    newNameCount = 0;
    while (*bufNameEnd)
    {
        while (*bufNameEnd && *bufNameEnd != ' ')
            ++bufNameEnd;
        newName[newNameCount] = new (std::nothrow) char[bufNameEnd - bufNameBegin + 1];
        if (!newName[newNameCount])
        {
            dealloc(newName, newNameCount);
            std::cout << "<Student could not be read.>\n";
            return;
        }
        for (unsigned i = 0; i < bufNameEnd - bufNameBegin; ++i)
            newName[newNameCount][i] = bufNameBegin[i];
        newName[newNameCount][bufNameEnd - bufNameBegin] = '\0';
        if (*bufNameEnd)
            ++bufNameEnd;
        bufNameBegin = bufNameEnd;
        ++newNameCount;
    }
    std::cout << "Enter student's ID: ";
    std::cin.getline(buf, INPUT_MAX);
    char *newFn = new (std::nothrow) char[strlen(buf) + 1];
    if (!newFn)
    {
        dealloc(newName, newNameCount);
        std::cout << "<Student could not be read.>\n";
        return;
    }
    strcpy(newFn, buf);
    std::cout << "Enter student's specialty: ";
    std::cin.getline(buf, INPUT_MAX);
    std::cout << "Enter student's credits: ";
    std::cin >> credits;

    if (fn)
        delete[] fn;
    fn = newFn;
    if (names)
        dealloc(names, namesCount);
    namesCount = newNameCount;
    names = newName;
    unsigned i = 0;
    while (i < spCount && strcmp(spArr[i]->getName(), buf))
        ++i;
    if (i < spCount)
    {
        specialty = spArr[i];
        spArr[i]->addStudent(this);
    }
    else
        specialty = nullptr;
    std::cout << "<Student read successfully.>\n";
}

unsigned Student::countNames(const char *s)
{
    if (!*s)
        return 0;
    unsigned res = 0;
    while (*s)
        res += *s++ == ' ';
    return res + 1;
}
