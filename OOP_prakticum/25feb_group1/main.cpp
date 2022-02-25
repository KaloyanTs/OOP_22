#include <iostream>
#include <cassert>
#include <cstring>
const size_t NAME_MAX = 16;
const size_t GRADE_COUNT = 6;

struct Record
{
    char *oldW = nullptr;
    char *newW = nullptr;
    bool init()
    {
        size_t L;
        std::cout << "Enter length of first word: ";
        std::cin >> L;
        oldW = new (std::nothrow) char[L + 1];
        if (!oldW)
            return false;
        std::cin.ignore();
        std::cout << "Enter the first word: ";
        std::cin.getline(oldW, L + 1);
        std::cout << "Enter length of second word: ";
        std::cin >> L;
        newW = new (std::nothrow) char[L + 1];
        if (!newW)
        {
            delete oldW;
            return false;
        }
        std::cin.ignore();
        std::cout << "Enter the second word: ";
        std::cin.getline(newW, L + 1);
        return true;
    }
    void print()
    {
        if (oldW)
            std::cout << oldW << " - " << newW << '\n';
    }
    void dealloc()
    {
        delete[] oldW;
        delete[] newW;
    }
};

struct Dictionary
{
    Record *records = nullptr;
    size_t length;
    bool init()
    {
        std::cout << "Enter count of records in the dictionary: ";
        std::cin >> length;
        records = new (std::nothrow) Record[length];
        if (!records)
            return false;
        unsigned i = 0;
        while (i < length && records[i].init())
            ++i;
        if (i < length)
            for (unsigned j = 0; j < i; ++j)
                records[j].dealloc();
        return i == length;
    }
    void print()
    {
        std::cout << "---------------\n";
        if (records)
            for (unsigned i = 0; i < length; ++i)
                records[i].print();
        std::cout << "---------------\n";
    }
    void dealloc()
    {
        if (records)
        {
            for (unsigned i = 0; i < length; ++i)
                records[i].dealloc();
            delete[] records;
        }
    }
};

void appendWord(const char *word, char *&output)
{
    while (*word)
        *output++ = *word++;
}

struct Sentence
{
    size_t length = 0;
    char *content = nullptr;
    bool init()
    {
        std::cout << "Enter length of the sentence: ";
        std::cin >> length;
        if (content)
            delete[] content;
        content = new (std::nothrow) char[length + 1];
        if (!content)
            return false;
        std::cin.ignore();
        std::cout << "Enter the sentence:\n";
        std::cin.getline(content, length + 1);
        return true;
    }
    void print()
    {
        if (content)
            std::cout << content << '\n';
    }
    unsigned searchRecord(const char *begin, const Record &rec)
    {
        const char *res = strstr(begin, rec.oldW);
        if (res != begin)
            return 0;
        return strlen(rec.oldW);
    }
    unsigned searchDict(const char *&begin, const Dictionary &dict)
    {
        unsigned res = 0;
        unsigned i = 0;
        while (i < dict.length && !res)
        {
            res = searchRecord(begin, dict.records[i]);
            if (!res)
                ++i;
        }
        begin += res;
        return i;
    }
    size_t maxSize(size_t length)
    {
        return (2 * length + 1 > 64 ? 2 * length + 1 : 64);
    }
    bool replace(const Dictionary &dict)
    {
        char *const newS = new (std::nothrow) char[maxSize(length)];
        if (!newS)
            return false;
        char *newSEnd = newS;
        const char *iter = content;
        unsigned res = 0;
        while (*iter)
        {
            res = searchDict(iter, dict);
            if (res < dict.length)
                appendWord(dict.records[res].newW, newSEnd);
            else
                *newSEnd++ = *iter++;
        }
        *newSEnd = '\0';
        delete[] content;
        content = new (std::nothrow) char[newSEnd - newS + 1];
        if (!content)
        {
            delete[] newS;
            return false;
        }
        strcpy(content, newS);
        length = newSEnd - newS;
        delete[] newS;
        return true;
    }
    void dealloc()
    {
        if (content)
            delete[] content;
    }
};

void Task1()
{
    Dictionary dict;
    if (!dict.init())
    {
        std::cout << "Not enough memory for the dictionary!\n";
        return;
    }
    size_t sentenceL;
    Sentence s;
    if (!s.init() || !s.replace(dict))
    {
        std::cout << "Not enough memory for the sentence!\n";
        dict.dealloc();
        s.dealloc();
        return;
    }
    s.print();
    s.dealloc();
    dict.dealloc();
}

struct Grade
{
    char name[NAME_MAX];
    unsigned value = 0;
};

struct Student
{
    char name[NAME_MAX];
    char fn[NAME_MAX];
    Grade grades[GRADE_COUNT];
};

void readStudent(Student &s)
{
    std::cout << "Enter student's name: ";
    std::cin.getline(s.name, NAME_MAX);
    std::cout << "Enter student's ID: ";
    std::cin.getline(s.fn, NAME_MAX);
    for (unsigned i = 0; i < GRADE_COUNT; ++i)
    {
        std::cout << "Enter name of course and grade #" << i + 1 << ":\n";
        if (i)
            std::cin.ignore();
        std::cin.getline(s.grades[i].name, NAME_MAX);
        std::cin >> s.grades[i].value;
        // std::cin >> (s.grades + i)->value;
    }
}

void printGrade(const Grade &g)
{
    std::cout << g.name << "\t- " << g.value << '\n';
}

void printStudent(const Student &s)
{
    std::cout << "Name: " << s.name << "\tID: " << s.fn << '\n';
    for (unsigned i = 0; i < GRADE_COUNT; ++i)
        printGrade(s.grades[i]);
}

void printStudents(const Student *arr, size_t n)
{
    for (unsigned i = 0; i < n; ++i)
    {
        std::cout << "Student #" << i + 1 << ":\n";
        printStudent(arr[i]);
    }
}

size_t readStudents(Student *&arr)
{
    size_t n;
    std::cout << "Enter count of students: ";
    std::cin >> n;
    arr = new Student[n];
    for (unsigned i = 0; i < n; ++i)
    {
        std::cout << "Student #" << i + 1 << " data:\n";
        std::cin.ignore();
        readStudent(arr[i]);
    }
    return n;
}

void deallocStudents(Student *&arr)
{
    if (arr)
        delete[] arr;
    arr = nullptr;
}

const Student *searchByName(const Student *s, size_t n, const char *name)
{
    unsigned i = 0;
    while (i < n && strcmp(s[i].name, name))
        ++i;
    return (i < n ? s + i : nullptr);
}

const Student *searchByFN(const Student *s, size_t n, const char *fn)
{
    unsigned i = 0;
    while (i < n && strcmp(s[i].fn, fn))
        ++i;
    return (i < n ? s + i : nullptr);
}

unsigned diffGrades(const Student &s)
{
    short res = 0;
    for (unsigned i = 0; i < GRADE_COUNT; ++i)
    {
        res |= (1 << (s.grades[i].value - 2));
    }
    short count = 0;
    while (res)
    {
        count += (res & 1);
        res >>= 1;
    }
    return count;
}

unsigned maxGrade(const Student &s)
{
    unsigned res = s.grades[0].value;
    for (unsigned i = 1; i < GRADE_COUNT; ++i)
        if (s.grades[i].value > res)
            res = s.grades[i].value;
    return res;
}

const char *favCourses(const Student &s)
{
    char *res = new char[GRADE_COUNT * NAME_MAX + 1];
    char *resEnd = res;
    unsigned max = maxGrade(s);
    for (unsigned i = 0; i < GRADE_COUNT; ++i)
        if (s.grades[i].value == max)
        {
            appendWord(s.grades[i].name, resEnd);
            *resEnd++ = ',';
            *resEnd++ = ' ';
        }
    if (resEnd != res)
        resEnd -= 2;
    *resEnd = '\0';
    char *buf = new char[strlen(res) + 1];
    strcpy(buf, res);
    delete[] res;
    return buf;
}

double performance(const Student &s)
{
    double sum = 0;
    for (unsigned i = 0; i < GRADE_COUNT; ++i)
        sum += s.grades[i].value;
    assert(GRADE_COUNT);
    return sum / GRADE_COUNT;
}

bool leftBeforeRight(const Student &s1, const Student &s2)
{
    double p1 = performance(s1), p2 = performance(s2);
    return (p1 > p2 || (p1 == p2 && strcmp(s1.fn, s2.fn)));
}

void swapStudents(Student &s1, Student &s2)
{
    Student tmp = s1; // bad, better with array of pointers
    s1 = s2;
    s2 = tmp;
}

void sortByPerformanceFN(Student *s, size_t n)
{
    unsigned min = 0;
    for (unsigned i = 0; i < n - 1; ++i)
    {
        min = i;
        for (unsigned j = i + 1; j < n; ++j)
            if (leftBeforeRight(s[j], s[min]))
                min = j;
        swapStudents(s[i], s[min]);
    }
}

int main()
{
    // Task1();
    Student *arr;
    size_t N = readStudents(arr);
    printStudent(*searchByFN(arr, N, "4MI0800017"));
    const Student &Ivan = *searchByName(arr, N, "Ivan");
    printStudent(Ivan);
    std::cout << "Ivan has " << diffGrades(Ivan) << " different grades.\n";
    const char *fav = favCourses(Ivan);
    std::cout << "Ivan's favourite course"
              << (strchr(fav, ',') ? "s are " : " is ")
              << fav << ".\n";
    sortByPerformanceFN(arr, N);
    printStudents(arr, N);
    deallocStudents(arr);
    delete[] fav;
    return 0;
}

// Task2 input:
// Student #1:
// Name: Ivan      ID: 4MI0800017
// DSTR    - 6
// ALG     - 4
// A1      - 3
// UP      - 6
// A2      - 3
// OOP     - 6
// Student #2:
// Name: Georgi    ID: 84435
// DSTR    - 6
// ALG     - 6
// A1      - 6
// UP      - 6
// A2      - 6
// OOP     - 6
// Student #3:
// Name: Atanas    ID: 84885
// DSTR    - 3
// ALG     - 3
// A1      - 3
// UP      - 6
// A2      - 3
// OOP     - 6