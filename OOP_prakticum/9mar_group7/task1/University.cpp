#include "University.hpp"

University::University()
{
    scientists = nullptr;
    countScientists = 0;
    std::cout << "<University created successfully.>\n";
}

void University::copy(const University &U)
{
    Scientist **newArr = new (std::nothrow) Scientist *[U.countScientists];
    if (!newArr)
    {
        std::cout << "<University could not be copied properly.>\n";
        return;
    }
    for (unsigned i = 0; i < U.countScientists; ++i)
    {
        newArr[i] = new (std::nothrow) Scientist(*U.scientists[i]);
        if (!newArr[i])
        {
            dealloc(newArr, i);
            std::cout << "<University could not be copied properly.>\n";
            return;
        }
    }
    countScientists = U.countScientists;
    std::cout << "<University copied successfully.>\n";
}

void University::sortByTitle()
{
    unsigned iMax = 0;
    for (unsigned i = 0; i < countScientists - 1; ++i)
    {
        iMax = i;
        for (unsigned j = i + 1; j < countScientists; ++j)
            if (scientists[iMax]->getTitle() < scientists[j]->getTitle())
                iMax = j;
        Scientist *tmp = scientists[i];
        scientists[i] = scientists[iMax];
        scientists[iMax] = tmp;
    }
}

void University::dealloc(Scientist **&arr, size_t size)
{
    for (unsigned i = 0; i < size; ++i)
        delete arr[i];
    delete[] arr;
    arr = nullptr;
}

University::University(const University &U)
{
    scientists = nullptr;
    countScientists = 0;
    copy(U);
    std::cout << "<University created successfully.>\n";
}

const University &University::operator=(const University &U)
{
    if (this != &U)
        copy(U);
    return *this;
}

University::~University()
{
    dealloc(scientists, countScientists);
    std::cout << "<University deleted successfully.>\n";
}

void University::print() const
{
    std::cout << "Name:\tTitle:\tSalary:\tProfit:\n";
    for (unsigned i = 0; i < countScientists; ++i)
        scientists[i]->print();
}

bool University::hireScientist(const Scientist &S)
{
    Scientist **newArr = new (std::nothrow) Scientist *[countScientists + 1];
    if (!newArr)
    {
        std::cout << "<Scientist could not be hired.>\n";
        return false;
    }
    newArr[countScientists] = new (std::nothrow) Scientist(S);
    if (!newArr[countScientists])
    {
        delete[] newArr;
        std::cout << "<Scientist could not be hired.>\n";
        return false;
    }
    for (unsigned i = 0; i < countScientists; ++i)
        newArr[i] = scientists[i];
    delete[] scientists;
    scientists = newArr;
    ++countScientists;
    std::cout << "<Scientist hired successfully.>\n";
    return true;
}

bool University::fireScientist(const char *name)
{
    unsigned i = searchScient(name);
    if (i == countScientists)
    {
        std::cout << "<Scientist could not be found.>\n";
        return false;
    }
    Scientist **newArr = new (std::nothrow) Scientist *[countScientists - 1];
    if (!newArr)
    {
        std::cout << "<Scientist could not be found.>\n";
        return false;
    }
    delete scientists[i];
    unsigned j = 0;
    for (unsigned j = 0; j < i; ++j)
        newArr[j] = scientists[j];
    for (unsigned j = i; j < countScientists - 1; ++j)
        newArr[j] = scientists[j + 1];
    delete[] scientists;
    scientists = newArr;
    --countScientists;
    std::cout << "<Scientist fired successfully.>\n";
    return true;
}

unsigned University::searchScient(const char *name) const
{
    unsigned i = 0;
    while (i < countScientists && strcmp(name, scientists[i]->getName()))
        ++i;
    return i;
}

bool University::elevateScientist(const char *name)
{
    unsigned i = searchScient(name);
    if (i == countScientists)
    {
        std::cout << "<Scientist could not be found.>\n";
        return false;
    }
    return scientists[i]->elevate();
}

void University::fireScientists(Title title)
{
    unsigned count = countScientistsByTitle(title);
    Scientist **newArr = new (std::nothrow) Scientist *[countScientists - count];
    if (!newArr)
        return;
    unsigned j = 0;
    for (unsigned i = 0; i < countScientists; ++i)
        if (scientists[i]->getTitle() == title)
            delete scientists[i];
        else
            newArr[j++] = scientists[i];
    delete[] scientists;
    scientists = newArr;
    countScientists -= count;
}

unsigned University::countScientistsByTitle(Title title)
{
    unsigned count = 0;
    for (unsigned i = 0; i < countScientists; ++i)
        count += title == scientists[i]->getTitle();
    return count;
}

unsigned University::getIncome() const
{
    unsigned income = 0;
    for (unsigned i = 0; i < countScientists; ++i)
        income += scientists[i]->getProfit();
    return income;
}

unsigned University::getExpenses() const
{
    unsigned expenses = 0;
    for (unsigned i = 0; i < countScientists; ++i)
        expenses += scientists[i]->getSalary();
    return expenses;
}
