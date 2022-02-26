#include <iostream>
#include <cmath>
#include <cassert>
#include <iomanip>
#include <cstring>
const size_t NAME_MAX = 16;

struct Complex
{
    double real = 0;
    double imaginary = 0;
    void init()
    {
        std::cin >> real >> imaginary;
    }
    void print() const
    {
        std::cout << std::fixed
                  << std::setprecision(2)
                  << real << " + " << imaginary << "i\n";
    }
};

void init(Complex &c)
{
    std::cin >> c.real >> c.imaginary;
}

void print(const Complex &c)
{
    std::cout << std::fixed
              << std::setprecision(2)
              << c.real << " + " << c.imaginary << "i\n";
}

void complexSum(const Complex &c1, const Complex &c2, Complex &c)
{
    c.real = c1.real + c2.real;
    c.imaginary = c1.imaginary + c2.imaginary;
}

void complexDiff(const Complex &c1, const Complex &c2, Complex &c)
{
    c.real = c1.real - c2.real;
    c.imaginary = c1.imaginary - c2.imaginary;
}

void complexMul(const Complex &c1, const Complex &c2, Complex &c)
{
    c.real = c1.real * c2.real - c1.imaginary * c2.imaginary;
    c.imaginary = c1.imaginary * c2.real + c1.real * c2.imaginary;
}

double getLength(const Complex &c)
{
    return sqrt(c.real * c.real + c.imaginary * c.imaginary);
}

void complexDiv(const Complex &c1, const Complex &c2, Complex &c)
{
    double l = getLength(c2);
    assert(l);
    c.real = c1.real * c2.real + c1.imaginary * c2.imaginary;
    c.real /= l;
    c.imaginary = c1.imaginary * c2.real - c1.real * c2.imaginary;
    c.imaginary /= l;
}

Complex getAverage(const Complex *const *arr, size_t n)
{
    Complex av;
    av.real = av.imaginary = 0;
    for (unsigned i = 0; i < n; ++i)
        complexSum(*arr[i], av, av);
    av.real /= n;
    av.imaginary /= n;
    return av;
}

bool leftBeforeRight(const Complex &c1, const Complex &c2)
{
    return getLength(c1) <= getLength(c2);
}

void swapComplexPointers(const Complex *&c1, const Complex *&c2)
{
    const Complex *c = c1;
    c1 = c2;
    c2 = c;
}

void sortComplexArray(const Complex *arr, size_t n)
// want first argument to be const Complex **
{
    unsigned iMin = 0;
    const Complex *p1 = nullptr, *p2 = nullptr;
    for (unsigned i = 0; i < n; ++i)
    {
        iMin = i;
        for (unsigned j = i + 1; j < n; ++j)
            if (!leftBeforeRight(arr[iMin], arr[j]))
                iMin = j;
        p1 = arr + i;
        p2 = arr + iMin;
        swapComplexPointers(p1, p2);
    }
}

void printComplexArray(const Complex *const *arr, size_t n)
{
    for (unsigned i = 0; i < n; ++i)
    {
        std::cout << i << ": ";
        arr[i]->print();
    }
}

void deallocComplexArray(Complex **&arr, size_t &n)
{
    for (unsigned i = 0; i < n; ++i)
        delete arr[i];
    delete[] arr;
    arr = nullptr;
    n = 0;
}

void Task1()
{
    size_t N;
    std::cout << "Enter count of complex numbers: ";
    std::cin >> N;
    Complex **arr = new (std::nothrow) Complex *[N];
    if (!arr)
    {
        std::cout << "Not enough memory for array!\n";
        return;
    }
    for (unsigned i = 0; i < N; ++i)
    {
        arr[i] = new Complex;
        std::cout << "Enter complex number #" << i + 1 << ": ";
        arr[i]->init();
    }
    sortComplexArray(*arr, N);
    // invalid conversion from "Complex **" to "const Complex **"
    printComplexArray(arr, N);
    std::cout << "Average of all numbers is: ";
    getAverage(arr, N).print();
    deallocComplexArray(arr, N);
}

struct Worker
{
    char name[NAME_MAX];
    unsigned salary;
    const Worker *boss = nullptr;
    void init(const char *_name, unsigned _salary, const Worker *_boss)
    {
        strcpy(name, _name);
        salary = _salary;
        boss = _boss;
    }
    void print() const
    {
        std::cout << "Name: " << name
                  << "\tSalary: " << salary
                  << "\tBoss: " << (boss ? boss->name : "-")
                  << '\n';
    }
};

struct Team
{
    char name[NAME_MAX];
    size_t count = 0;
    Worker **workers = nullptr;
    void init(const char *_name, Worker **list, size_t listCount)
    {
        strcpy(name, _name);
        workers = list;
        count = listCount;
    }
    void print() const
    {
        std::cout << "Team name: " << name << '\n';
        for (unsigned i = 0; i < count; ++i)
        {
            std::cout << '\t';
            workers[0][i].print();
        }
    }
    bool isInTeam(const char *name)
    {
        unsigned i = 0;
        while (i < count && strcmp(workers[i]->name, name))
            ++i;
        return i < count;
    }
};

struct Company
{
    char name[NAME_MAX];
    size_t count = 0;
    Team **teams = nullptr;
    void init(const char *_name, Team **list, size_t listCount)
    {
        strcpy(name, _name);
        count = listCount;
        teams = list;
    }
    void print() const
    {
        std::cout << "Company name: " << name << '\n';
        for (unsigned i = 0; i < count; ++i)
        {
            std::cout << "Team #" << i + 1 << ":\n";
            teams[i]->print();
        }
    }
    bool isWorkingHere(const char *name)
    {
        unsigned i = 0;
        while (i < count && !teams[i]->isInTeam(name))
            ++i;
        return i < count;
    }
    void showGM(const Worker &w)
    {
        const Worker *ptr = &w;
        while (ptr->boss)
        {
            ptr = ptr->boss;
        }
        std::cout << ptr->name;
    }
};

void Task2()
{
    const size_t WORKER_COUNT_MAX = 16;
    const size_t TEAM_COUNT_MAX = 4;
    size_t count = 12;
    Worker list[WORKER_COUNT_MAX];
    list[0].init("Ivan", 6000, &list[4]);
    list[1].init("Pesho", 4000, &list[0]);
    list[2].init("Rumen", 78000, &list[4]);
    list[3].init("Teo", 3508, &list[2]);
    list[4].init("Az", 547, nullptr);
    list[5].init("Toi", 1000, &list[3]);

    list[6].init("Joe", 6000, &list[8]);
    list[7].init("William", 4000, &list[8]);
    list[8].init("George", 78000, &list[8]);
    list[9].init("Fred", 3508, &list[6]);
    list[10].init("Khloe", 548, nullptr);
    list[11].init("Tom", 1000, &list[6]);

    size_t Team1WorkersCount = 6;
    Worker *Team1Workers[Team1WorkersCount];
    Team1Workers[0] = &list[0];
    Team1Workers[1] = &list[1];
    Team1Workers[2] = &list[2];
    Team1Workers[3] = &list[3];
    Team1Workers[4] = &list[4];
    Team1Workers[5] = &list[5];

    size_t Team2WorkersCount = 6;
    Worker *Team2Workers[Team2WorkersCount];
    Team2Workers[0] = &list[6];
    Team2Workers[1] = &list[7];
    Team2Workers[2] = &list[8];
    Team2Workers[3] = &list[9];
    Team2Workers[4] = &list[10];
    Team2Workers[5] = &list[11];

    Team Teamlist[TEAM_COUNT_MAX];
    Teamlist[0].init("BG", Team1Workers, Team1WorkersCount);
    Teamlist[1].init("USA", Team2Workers, Team2WorkersCount);

    const size_t cmpnTeamCount = 2;
    Team *cmpnTeams[cmpnTeamCount];
    cmpnTeams[0] = &Teamlist[1];
    cmpnTeams[1] = &Teamlist[0];

    Company cmpn;
    cmpn.init("Nay-dobrata firma", cmpnTeams, cmpnTeamCount);

    cmpn.print();
    const char *name1 = "Boris";
    std::cout << name1 << " is ";
    if (!cmpn.isWorkingHere(name1))
        std::cout << "NOT ";
    std::cout << "working at " << cmpn.name << ".\n";

    const char *name2 = "George";
    std::cout << name2 << " is ";
    if (!cmpn.isWorkingHere(name2))
        std::cout << "NOT ";
    std::cout << "working at " << cmpn.name << ".\n";

    const Worker &ref = list[5];
    std::cout << ref.name << "'s highest boss is ";
    cmpn.showGM(ref);
    std::cout << ".\n";
}

int main()
{
    // Task1();
    Task2();

    return 0;
}