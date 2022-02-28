#include <iostream>
#include <cstring>
const size_t NAME_MAX = 16;
const size_t GRADE_COUNT_MAX = 3;

struct Distance
{
    unsigned inch = 0;
    unsigned foot = 0;
};

void print(const Distance &d)
{
    std::cout << d.inch << '\'' << d.foot << "\'\'\n";
}

void sumDistances(const Distance &d1, const Distance &d2, Distance &res)
{
    res.inch = d1.inch + d2.inch;
    res.foot = d1.foot + d2.foot;
    if (res.foot >= 12)
    {
        res.foot -= 12;
        ++res.inch;
    }
}

struct TimePeriod
{
    short hour = 0, minute = 0, second = 0;
};

void print(const TimePeriod &tP)
{
    std::cout.fill('0');
    std::cout.width(2);
    std::cout << tP.hour << ':';
    std::cout.fill('0');
    std::cout.width(2);
    std::cout << tP.minute << ':';
    std::cout.fill('0');
    std::cout.width(2);
    std::cout << tP.second << '\n';
}

void TimeDiff(const TimePeriod &t1, const TimePeriod &t2, TimePeriod &res)
{
    unsigned secTime1 = (t2.hour * 60 + t2.minute) * 60 + t2.second;
    unsigned secTime2 = (t1.hour * 60 + t1.minute) * 60 + t1.second;
    if (secTime1 < secTime2)
        secTime1 += 24 * 60 * 60;
    secTime1 -= secTime2;
    res.second = secTime1 % 60;
    secTime1 /= 60;
    res.minute = secTime1 % 60;
    res.hour = secTime1 / 60;
}

struct Grade
{
    char name[NAME_MAX];
    unsigned value = 0;
    void init()
    {
        std::cout << "Enter subject name and grade:\n";
        std::cin.ignore();
        std::cin.getline(name, NAME_MAX);
        std::cin >> value;
    }
    void print() const
    {
        std::cout << name << ": " << value << '\n';
    }
};

struct Student
{
    char name[NAME_MAX];
    char fn[NAME_MAX];
    Grade grades[GRADE_COUNT_MAX];
    void init()
    {
        std::cout << "Enter student's first name: ";
        std::cin.ignore();
        std::cin.getline(name, NAME_MAX);
        std::cout << "Enter student's ID: ";
        std::cin.getline(fn, NAME_MAX);
        for (unsigned i = 0; i < GRADE_COUNT_MAX; ++i)
        {
            std::cout << i + 1 << ": ";
            grades[i].init();
        }
    }
    void print() const
    {
        std::cout << "Name: " << name << "\tID: " << fn << '\n';
        for (unsigned i = 0; i < GRADE_COUNT_MAX; ++i)
        {
            std::cout << "\tgrade #" << i + 1 << ": ";
            grades[i].print();
        }
    }
};

void deallocStudentArray(Student **&arr, size_t count)
{
    for (unsigned i = 0; i < count; ++i)
        delete arr[i];
    delete[] arr;
    arr = nullptr;
}

Student **createStudentArray(size_t &n)
{
    std::cout << "Enter count of students: ";
    std::cin >> n;
    Student **arr = new Student *[n];
    if (!arr)
    {
        n = 0;
        return nullptr;
    }
    for (unsigned i = 0; i < n; ++i)
    {
        std::cout << "Enter data for student #" << i + 1 << ":\n";
        arr[i] = new Student;
        if (!arr[i])
        {
            deallocStudentArray(arr, i);
            n = 0;
            return nullptr;
        }
        arr[i]->init();
    }
    return arr;
}

void printStudentArray(Student **arr, size_t count)
{
    for (unsigned i = 0; i < count; ++i)
    {
        std::cout << "Student #" << i + 1 << ":\n";
        arr[i]->print();
    }
}

void showAchievedGrade(Student **arr, size_t count, unsigned grade)
{
    for (unsigned i = 0; i < count; ++i)
    {
        bool found = false;
        std::cout << arr[i]->name << ": ";
        for (unsigned j = 0; j < GRADE_COUNT_MAX; ++j)
            if (arr[i]->grades[j].value > grade)
            {
                std::cout << arr[i]->grades[j].name << " ";
                found = true;
            }
        if (!found)
            std::cout << "No such subjects.";
        std::cout << '\n';
    }
}

double averagePerformance(const Student &s)
{
    double sum = 0;
    for (unsigned i = 0; i < GRADE_COUNT_MAX; ++i)
        sum += s.grades[i].value;
    return sum / GRADE_COUNT_MAX;
}

bool toBeSwapped(const Student &s1, const Student &s2)
{
    double avS1 = averagePerformance(s1);
    double avS2 = averagePerformance(s2);
    return (avS1 < avS2 || (avS1 == avS2 && strcmp(s1.name, s2.name) > 0));
}

void swapStudentPointers(const Student *s1, const Student *s2)
{
    const Student *tmp = s1;
    s1 = s2;
    s2 = tmp;
}

void sortStudentArray(const Student *arr, size_t count)
//първият аргумент да е const Student **
{
    unsigned iMin = 0;
    for (unsigned i = 0; i < count - 1; ++i)
    {
        iMin = i;
        for (unsigned j = 0; j < count; ++j)
            if (toBeSwapped(arr[iMin], arr[j]))
                // if (toBeSwapped(*arr[iMin], *arr[j]))
                iMin = j;
        swapStudentPointers(arr + i, arr + iMin);
        // swapStudentPointers(arr[i], arr[iMin]);
    }
}

int main()
{
    TimePeriod t = {2, 15, 9}, p = {5, 13, 56};
    print(t);
    print(p);
    TimePeriod diff;
    TimeDiff(t, p, diff);
    print(diff);

    size_t count = 0;
    Student **arr = createStudentArray(count);

    showAchievedGrade(arr, count, 4);
    sortStudentArray(*arr, count);
    // тук да подаваме само arr
    // invalid conversion from 'Student **' to 'const Student**'
    // има ли как да се заобиколи?
    printStudentArray(arr, count);

    deallocStudentArray(arr, count);
    return 0;
}

//Input example

// 3

// Atanas
// 34lnl4f4
// math 5
// Physics 4
// Biology 6

// Ivan
// onon3o3no
// Math 4
// Physics 6
// Biology 5

// Boris
// do4i3noio
// Math 3
// Physics 3
// Biology 3