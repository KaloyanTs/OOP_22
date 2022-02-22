#include <iostream>
#include <cstring>
const unsigned NAME_MAX = 32;

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
    std::cout << "Summary:\n";
    for (unsigned i = 0; i < b.subjectCount; ++i)
    {
        std::cout << '\t';
        printSubject(b.subjects[i]);
    }
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

int main()
{
    // Task1();
    Task2();
    return 0;
}