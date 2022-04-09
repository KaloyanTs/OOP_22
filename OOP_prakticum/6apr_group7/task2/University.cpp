#include "University.hpp"

University::University()
    : size(0),
      capacity(INIT_CAPACITY),
      students(new (std::nothrow) Student *[INIT_CAPACITY]),
      name("unknown")
{
    assert(students);
}

void University::copy(const University &other)
{
    clear();
    size = other.size;
    capacity = other.capacity;
    strcpy(name, other.name);
    students = new (std::nothrow) Student *[capacity];
    assert(students);
    for (unsigned i = 0; i < size; ++i)
    {
        students[i] = new (std::nothrow) Student(*other.students[i]);
        assert(students[i]);
    }
}

void University::clear()
{
    for (unsigned i = 0; i < size; ++i)
        delete students[i];
    delete[] students;
}

University::University(const University &other)
    : students(nullptr)
{
    copy(other);
}

University &University::write()
{
    char *path = new (std::nothrow) char[strlen("binary_.dat") + strlen(name) + 1];
    assert(path);
    strcpy(path, "binary_");
    strcat(path, name);
    strcat(path, ".dat");
    std::ofstream out;
    out.open(path, std::ios::binary);
    assert(out.is_open());
    out << size << '\n';
    for (unsigned i = 0; i < size; ++i)
        out << *students[i];
    out.close();
    delete[] path;
    return *this;
}

University &University::operator=(const University &other)
{
    if (this != &other)
        copy(other);
    return *this;
}

University &University::addStudent(const Student &S)
{
    if (size == capacity)
        expand(2 * capacity);
    students[size] = new (std::nothrow) Student(S);
    assert(students[size++]);
    return *this;
}

void University::expand(size_t newCap)
{
    assert(newCap >= capacity);
    capacity = newCap;
    Student **newArr = new Student *[capacity];
    assert(newArr);
    for (unsigned i = 0; i < size; ++i)
        newArr[i] = students[i];
    delete[] students;
    students = newArr;
}

University &University::removeStudent(const char *name)
{
    unsigned pos = 0;
    while (pos < size && strcmp(name, students[pos]->name))
        ++pos;
    if (pos == size)
        return *this;
    delete students[pos];
    for (unsigned i = pos; i < size - 1; ++i)
        students[i] = students[i + 1];
    --size;
    return *this;
}

University::University(const char *_name)
{
    strcpy(name, _name);
    std::ifstream in;
    char *filePath = new (std::nothrow) char[strlen("binary_.dat") + strlen(name) + 1];
    assert(filePath);
    strcpy(filePath, "binary_");
    strcat(filePath, name);
    strcat(filePath, ".dat");
    in.open(filePath);
    assert(in.is_open());
    in >> size;
    capacity = size;
    students = new (std::nothrow) Student *[capacity];
    assert(students);
    char buf[NAME_MAX];
    unsigned bufAge;
    for (unsigned i = 0; i < size; ++i)
    {
        in.ignore();
        in.getline(buf, NAME_MAX, '\t');
        in >> bufAge;
        students[i] = new (std::nothrow) Student(buf, bufAge);
        assert(students[i]);
    }
    delete[] filePath;
}

std::ostream &operator<<(std::ostream &out, const University &U)
{
    std::cout << U.name << '\n';
    for (unsigned i = 0; i < U.size; ++i)
        std::cout << '\t' << *U.students[i];
    return out;
}

University::~University()
{
    std::ofstream out;
    out.open("universities.txt", std::ios::app);
    assert(out.is_open());
    out << name << '\n'
        << size << '\n';
    for (unsigned i = 0; i < size; ++i)
        out << *students[i];
    out.close();
    clear();
}