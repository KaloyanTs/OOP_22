#include "Scientist.hpp"

Scientist::Scientist()
{
    name = nullptr;
    salary = 0;
    profit = 0;
    std::cout << "<Scientist created successfully.>\n";
}

Scientist::Scientist(const char *_n, unsigned _s, unsigned _p)
{
    name = new (std::nothrow) char[strlen(_n) + 1];
    if (!name)
    {
        std::cout << "<Scientist could not be copied properly.>\n";
        salary = profit = 0;
        return;
    }
    strcpy(name, _n);
    salary = _s;
    profit = _p;
    title = Title(true);
    std::cout << "<Scinetist created successfully.>\n";
}

Scientist::Scientist(const Scientist &S)
{
    name = nullptr;
    salary = profit = 0;
    title = Title();
    copy(S);
    std::cout << "<Scientist created successfully.>\n";
}

const Scientist &Scientist::operator=(const Scientist &S)
{
    if (this != &S)
        copy(S);
    return *this;
}

Scientist::~Scientist()
{
    delete[] name;
    std::cout << "<Scientist deleted successfully.>\n";
}

void Scientist::copy(const Scientist &S)
{
    char *newName = new (std::nothrow) char[strlen(S.name) + 1];
    if (!newName)
    {
        std::cout << "<Scientist could not be created properly.>\n";
        return;
    }
    strcpy(newName, S.name);
    if (name)
        delete[] name;
    name = newName;
    salary = S.salary;
    profit = S.profit;
    title = S.title;
    std::cout << "<Scientist copied successfully.>\n";
}

void Scientist::print() const
{
    std::cout << (name ? name : " - ")
              << '\t' << salary << '\t'
              << profit << '\t';
    title.print();
    std::cout << '\n';
}

bool Scientist::elevate()
{
    if (!title.canElevate())
        return false;
    title.elevate();
    salary += TITLE_SALARY_DIFFERENCE;
    std::cout << "<Scientist elevated successfully.>\n";
    return true;
}

void Scientist::read()
{
    char newName[NAME_MAX];
    std ::cout << "Enter scientist's name: ";
    std::cin.getline(newName, NAME_MAX);
    char *newNamePtr = new (std::nothrow) char[strlen(newName) + 1];
    if (!newNamePtr)
    {
        std::cout << "<Scientist could not be read properly.>\n";
        return;
    }
    strcpy(newNamePtr, newName);
    std::cout << "Enter scientist's title: ";
    std::cin.getline(newName, NAME_MAX);
    title = Title(strchr("aACP", *newName));
    if (*newName != 'a')
        switch (*newName)
        {
        case 'P':
            title.elevate();
        case 'A':
            title.elevate();
        case 'C':
            title.elevate();
            break;
        default:
            title = Title();
        }
    std::cout << "Enter scientist's salary: ";
    std::cin >> salary;
    std::cout << "Enter scientist's profit: ";
    std::cin >> profit;
    if (name)
        delete[] name;
    name = newNamePtr;
    std::cout << "<Scientist read properly.>\n";
}