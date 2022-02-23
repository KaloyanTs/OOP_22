#include <iostream>
#include <iomanip>
#include <cstring>
#include <cassert>
const unsigned NAME_MAX = 32;
const unsigned FN_MAX = 32;

enum SwordType
{
    SHARP,
    HEAVY_DAMAGE,
    COMPACT
};

void inputSwordType(SwordType &sT)
{
    unsigned buf;
    std::cin >> buf;
    if (buf == 1)
        sT = SHARP;
    else if (buf == 2)
        sT = HEAVY_DAMAGE;
    else if (buf == 3)
        sT = COMPACT;
    else
        std::cout << "Invalid input!\n";
}

void printSwordType(const SwordType &sT)
{
    if (sT == SHARP)
        std::cout << "SHARP";
    else if (sT == HEAVY_DAMAGE)
        std::cout << "HEAVY_DAMAGE";
    else if (sT == COMPACT)
        std::cout << "COMPACT";
    else
        std::cout << "Not initialized!";
}

struct Sword
{
    char model[NAME_MAX];
    unsigned power;
    SwordType type;
    unsigned forgeYear;
};

struct Warrior
{
    char name[NAME_MAX];
    unsigned age;
    Sword s;
};

void initializeSword(Warrior &warrior)
{
    std::cout << "Enter sword model: ";
    std::cin.getline(warrior.s.model, NAME_MAX);
    std::cout << "Enter sword power: ";
    std::cin >> warrior.s.power;
    std::cout << "Enter sword type: ";
    inputSwordType(warrior.s.type);
    std::cout << "Enter year of forging of the sword: ";
    std::cin >> warrior.s.forgeYear;
    std::cin.ignore();
}

void initializeWarrior(Warrior &warrior)
{
    std::cout << "Enter warrior's name: ";
    std::cin.getline(warrior.name, NAME_MAX);
    std::cout << "Enter warrior's age: ";
    std::cin >> warrior.age;
    std::cout << "Initialize the sword:\n";
    std::cin.ignore();
    initializeSword(warrior);
}

void printWarrior(const Warrior &warrior)
{
    std::cout << "Name: " << warrior.name << '\n';
    std::cout << "Age: " << warrior.age << '\n';
    std::cout << "Sword:\n";
    std::cout << "\tModel: " << warrior.s.model << '\n';
    std::cout << "\tPower: " << warrior.s.power << '\n';
    std::cout << "\tType: ";
    printSwordType(warrior.s.type);
    std::cout << "\n\tForged in: " << warrior.s.forgeYear << '\n';
}

void Task1()
{
    Warrior w;
    initializeWarrior(w);
    printWarrior(w);
}

struct Subject
{
    char name[NAME_MAX] = "";
    unsigned *grades = nullptr;
    unsigned gradesCount = 0;
};

void initSubject(Subject &s)
{
    std::cout << "Enter subject's name: ";
    std::cin.getline(s.name, NAME_MAX);
    std::cout << "Enter grades count: ";
    std::cin >> s.gradesCount;
    if (s.gradesCount)
    {
        if (s.grades)
            delete[] s.grades;
        s.grades = new unsigned[s.gradesCount];
        std::cout << "Enter " << s.gradesCount << " grades for " << s.name << '\n';
        for (unsigned i = 0; i < s.gradesCount; ++i)
            std::cin >> s.grades[i];
        std::cin.ignore();
    }
}

void printSubject(const Subject &s)
{
    if (!s.grades)
        return;
    std::cout << s.name << ": ";
    for (unsigned i = 0; i < s.gradesCount; ++i)
        std::cout << s.grades[i] << ' ';
    std::cout << '\n';
}

void deallocSubject(Subject &s)
{
    if (!s.grades)
        return;
    delete[] s.grades;
}

struct Book
{
    unsigned subjectCount = 0;
    Subject *subjects = nullptr;
};

void initBook(Book &b)
{
    std::cout << "Enter count of subjects: ";
    std::cin >> b.subjectCount;
    std::cin.ignore();
    if (b.subjectCount)
    {
        b.subjects = new Subject[b.subjectCount];
        for (unsigned i = 0; i < b.subjectCount; ++i)
            initSubject(b.subjects[i]);
    }
}

void deallocBook(Book &b)
{
    if (b.subjects)
    {
        for (unsigned i = 0; i < b.subjectCount; ++i)
            deallocSubject(b.subjects[i]);
        delete[] b.subjects;
    }
}

double getAverage(const Subject &s)
{
    double sum = 0;
    for (unsigned i = 0; i < s.gradesCount; ++i)
        sum += s.grades[i];
    return sum / s.gradesCount;
}

void summarizeSubject(const Book &b, const char *s)
{
    unsigned i = 0;
    while (i < b.subjectCount && strcmp(b.subjects[i].name, s))
        ++i;
    if (i == b.subjectCount)
    {
        std::cout << "No such subject!\n";
        return;
    }
    printSubject(b.subjects[i]);
}

void summarizeGradebook(const Book &b)
{
    double sum = 0;
    std::cout << "Summary:\n";
    for (unsigned i = 0; i < b.subjectCount; ++i)
    {
        std::cout << '\t';
        printSubject(b.subjects[i]);
        sum += getAverage(b.subjects[i]);
    }
    std::cout << "Average: " << std::fixed << std::setprecision(2) << sum / b.subjectCount << '\n';
}

void addGradeToSubject(Book &b, const char *sName, unsigned grade)
{
    if (!b.subjects)
        return;
    unsigned i = 0;
    while (i < b.subjectCount && strcmp(b.subjects[i].name, sName))
        ++i;
    if (i == b.subjectCount)
    {
        std::cout << "No such subject!\n";
        return;
    }
    unsigned *newGrades = new unsigned[b.subjects[i].gradesCount + 1];
    for (unsigned j = 0; j < b.subjects[i].gradesCount; ++j)
        newGrades[j] = b.subjects[i].grades[j];
    newGrades[b.subjects[i].gradesCount++] = grade;
    if (b.subjects[i].grades)
        delete[] b.subjects[i].grades;
    b.subjects[i].grades = newGrades;
}

bool gradeInSubject(const Subject &s, unsigned grade)
{
    if (!s.grades)
        return false;
    unsigned i = 0;
    while (i < s.gradesCount && s.grades[i] != grade)
        ++i;
    return i < s.gradesCount;
}

bool checkForGrade(const Book &b, const char *s, unsigned grade)
{
    if (!b.subjects)
        return false;
    unsigned i = 0;
    while (i < b.subjectCount && strcmp(b.subjects[i].name, s))
        ++i;
    return i < b.subjectCount && gradeInSubject(b.subjects[i], grade);
}

void Task2()
{
    Book b;
    initBook(b);
    summarizeSubject(b, "Math");
    addGradeToSubject(b, "Math", 6);
    summarizeGradebook(b);
    std::cout << std::boolalpha << checkForGrade(b, "Math", 3) << '\n';
    deallocBook(b);
}

struct Course
{
    char name[NAME_MAX];
    unsigned grade;
};

struct StudentsBook
{
    char name[NAME_MAX] = "";
    char fn[FN_MAX];
    unsigned gradesCount = 0;
    Course *courses = nullptr;
};

void initStudentsBook(StudentsBook &sB)
{
    std::cout << "Enter name of the student: ";
    std::cin.getline(sB.name, NAME_MAX);
    std::cout << "Enter student's faculty ID: ";
    std::cin.getline(sB.fn, FN_MAX);
    sB.gradesCount = 0;
    sB.courses = nullptr;
}

void addNewGrade(StudentsBook &sB, const char *c, unsigned g)
{
    assert(g >= 2 && g <= 6);
    unsigned i = 0;
    while (i < sB.gradesCount && strcmp(sB.courses[i].name, c))
        ++i;
    if (i < sB.gradesCount)
    {
        sB.courses[i].grade = g;
        return;
    }
    Course *buf = new Course[sB.gradesCount + 1];
    for (unsigned j = 0; j < sB.gradesCount; ++j)
        buf[j] = sB.courses[j];
    strcpy(buf[sB.gradesCount].name, c);
    buf[sB.gradesCount++].grade = g;
    if (sB.courses)
        delete[] sB.courses;
    sB.courses = buf;
}

void printCourse(const Course &c)
{
    std::cout << c.name << '\t' << c.grade << '\n';
}

void printStBook(const StudentsBook &sB)
{
    std::cout << sB.name << '\t' << sB.fn << '\n';
    for (unsigned i = 0; i < sB.gradesCount; ++i)
        printCourse(sB.courses[i]);
}

void burnStBook(StudentsBook &sB)
{
    if (sB.courses)
        delete[] sB.courses;
    sB.gradesCount = 0;
    strcpy(sB.name, "");
    strcpy(sB.fn, "");
}

void swapCourses(Course &a, Course &b)
{
    Course tmp = a;
    a = b;
    b = tmp;
}

void sortCoursesByGrades(StudentsBook &sB)
{
    unsigned iMin;
    for (unsigned i = 0; i < sB.gradesCount - 1; ++i)
    {
        iMin = i;
        for (unsigned j = i + 1; j < sB.gradesCount; ++j)
        {
            if (sB.courses[j].grade > sB.courses[iMin].grade)
                iMin = j;
        }
        swapCourses(sB.courses[i], sB.courses[iMin]);
    }
}

double AvPerformance(const StudentsBook &sB, bool withFailed)
{
    if (!sB.gradesCount)
        return 0;
    double sum = 0;
    unsigned count = 0;
    for (unsigned i = 0; i < sB.gradesCount; ++i)
    {
        if (withFailed || sB.courses[i].grade >= 3)
        {
            ++count;
            sum += sB.courses[i].grade;
        }
    }
    return sum / count;
}

unsigned countOfFailed(const StudentsBook &sB)
{
    unsigned c = 0;
    for (unsigned i = 0; i < sB.gradesCount; ++i)
        c += (sB.courses[i].grade >= 3);
    return c;
}

bool isAllowed(const StudentsBook &sB)
{
    unsigned failed = countOfFailed(sB);
    return failed < 4 || (failed == 4 && AvPerformance(sB, true) >= 3);
}

bool isStipendiant(const StudentsBook &sB)
{
    return !countOfFailed(sB) && AvPerformance(sB, true) >= 5;
}

int main()
{
    // Task1();
    // Task2();
    StudentsBook sB;
    initStudentsBook(sB);
    addNewGrade(sB, "DIS", 3);
    addNewGrade(sB, "IP", 5);
    addNewGrade(sB, "IP", 6);
    addNewGrade(sB, "DS", 2);
    addNewGrade(sB, "ALGEBRA", 5);
    printStBook(sB);
    sortCoursesByGrades(sB);
    printStBook(sB);
    std::cout << sB.name << "\'s performance (with failed) is "
              << std::fixed << std::setprecision(2)
              << AvPerformance(sB, true) << '\n';
    std::cout << sB.name << "\'s performance (without failed) is "
              << std::fixed << std::setprecision(2)
              << AvPerformance(sB, false) << '\n';
    std::cout << "The student is ";
    if (!isAllowed(sB))
        std::cout << "NOT ";
    std::cout << "passing the semester.\n";

    std::cout << "The student is ";
    if (!isStipendiant(sB))
        std::cout << "NOT ";
    std::cout << "taking scholarship.\n";
    burnStBook(sB);

    return 0;
}