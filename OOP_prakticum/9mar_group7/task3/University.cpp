#include "University.hpp"

University::University()
{
    specialties = nullptr;
    subjects = nullptr;
    spCount = subCount = 0;
    spCapacity = subCapacity = 0;
    std::cout << "<University created successfully.>\n";
}

void University::copy(const University &U)
{
    Specialty **newSp = new (std::nothrow) Specialty *[U.spCapacity];
    if (!newSp)
    {
        std::cout << "<University could not be copied.>\n";
        return;
    }
    Subject **newSub = new (std::nothrow) Subject *[U.subCapacity];
    if (!newSub)
    {
        delete[] newSp;
        std::cout << "<University could not be copied.>\n";
        return;
    }
    for (unsigned i = 0; i < U.spCount; ++i)
    {
        newSp[i] = new (std::nothrow) Specialty(*U.specialties[i]);
        if (!newSp[i])
        {
            deallocSp(newSp, i);
            delete[] newSub;
            std::cout << "<University could not be copied.>\n";
            return;
        }
    }
    for (unsigned i = 0; i < U.spCount; ++i)
    {
        newSub[i] = new (std::nothrow) Subject(*U.subjects[i]);
        if (!newSub[i])
        {
            deallocSp(newSp, U.spCount);
            deallocSub(newSub, i);
            std::cout << "<University could not be copied.>\n";
            return;
        }
    }
    deallocSp(specialties, spCount);
    deallocSub(subjects, subCount);
    spCount = U.spCount;
    subCount = U.subCount;
    spCapacity = U.spCapacity;
    subCapacity = U.subCapacity;
    specialties = newSp;
    subjects = newSub;
    std::cout << "<University copied successfully.>\n";
}

University::University(const University &U)
{
    specialties = nullptr;
    subjects = nullptr;
    spCount = subCount = 0;
    spCapacity = subCapacity = 0;
    copy(U);
    std::cout << "<University created successfully.>\n";
}

const University &University::operator=(const University &U)
{
    if (this != &U)
        copy(U);
    return *this;
}

void University::readNewSpecialty()
{
    char buf[INPUT_MAX];
    std::cout << "Enter new specialty's name: ";
    std::cin.getline(buf, INPUT_MAX);
    Specialty *inputSp = new (std::nothrow) Specialty(buf);
    if (!inputSp)
    {
        std::cout << "<Specialty could not be added.>\n";
        return;
    }
    if (spCount == spCapacity)
    {
        size_t newSpCap = (spCapacity ? 2 * spCapacity : 1);
        Specialty **newSp = new (std::nothrow) Specialty *[newSpCap];
        if (!newSp)
        {
            std::cout << "<Specialty could not be added.>\n";
            delete inputSp;
            return;
        }
        for (unsigned i = 0; i < spCount; ++i)
            newSp[i] = specialties[i];
        delete[] specialties;
        specialties = newSp;
        spCapacity = newSpCap;
    }
    specialties[spCount++] = inputSp;
    std::cout << "<Specialty added successfully.>\n";
}

void University::readNewSubject()
{
    char buf[INPUT_MAX];
    Subject *inputSub = new (std::nothrow) Subject;
    if (!inputSub)
    {
        std::cout << "<Subject could not be added.>\n";
        return;
    }
    inputSub->read(specialties, spCount);
    if (subCount == subCapacity)
    {
        size_t newSubCap = (subCapacity ? 2 * subCapacity : 1);
        Subject **newSub = new (std::nothrow) Subject *[newSubCap];
        if (!newSub)
        {
            std::cout << "<Subject could not be added.>\n";
            delete inputSub;
            return;
        }
        for (unsigned i = 0; i < subCount; ++i)
            newSub[i] = subjects[i];
        delete[] subjects;
        subjects = newSub;
        subCapacity = newSubCap;
    }
    subjects[subCount++] = inputSub;
    std::cout << "<Subjct added successfully.>\n";
}

void University::printStudents() const
{
    const Student **bufArr = nullptr;
    size_t bufCount;
    for (unsigned i = 0; i < spCount; ++i)
        specialties[i]->print();
}

void University::printStructure() const
{
    std::cout << "Specialties:\n";
    if (spCount)
        for (unsigned i = 0; i < spCount; ++i)
            std::cout << '\t' << i + 1 << ": " << specialties[i]->getName() << '\n';
    std::cout << "Subjects:\n";
    if (subCount)
        for (unsigned i = 0; i < subCount; ++i)
        {
            std::cout << '\t' << i + 1<<": ";
            subjects[i]->print();
        }
}

University::~University()
{
    for (unsigned i = 0; i < spCount; ++i)
        delete specialties[i];
    delete[] specialties;
    for (unsigned i = 0; i < spCount; ++i)
        delete subjects[i];
    delete[] subjects;
    std::cout << "<University deleted successfully.>\n";
}

void University::deallocSp(Specialty **&spArr, size_t size)
{
    for (unsigned i = 0; i < size; ++i)
        delete spArr[i];
    delete[] spArr;
    spArr = nullptr;
}

void University::deallocSub(Subject **&subArr, size_t size)
{
    for (unsigned i = 0; i < size; ++i)
        delete subArr[i];
    delete[] subArr;
    subArr = nullptr;
}
