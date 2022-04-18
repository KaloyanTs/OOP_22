#include "Student.hpp"

Student::Student(const char *_name,
                 const char *_fn,
                 float _avg,
                 char _group)
    : avg(_avg), group(_group), name(new char[strlen(_name) + 1]), fn(new char[strlen(_fn) + 1])
{
    strcpy(name, _name);
    strcpy(fn, _fn);
}

Student::Student(const Student &other)
    : name(nullptr), fn(nullptr)
{
    copy(other);
}

void Student::writeToBin(std::ofstream &ofs) const
{
    size_t length = strlen(name);
    ofs.write((const char *)&length, sizeof(length));
    ofs.write(name, length);
    length = strlen(fn);
    ofs.write((const char *)&length, sizeof(length));
    ofs.write(fn, length);
    ofs.write((const char *)&avg, sizeof(avg));
    ofs.write((const char *)&group, sizeof(group));
}

void Student::readFromBin(std::ifstream &ifs)
{
    clear();
    size_t length;
    ifs.read((char *)&length, sizeof(length));
    name = new char[length + 1];
    ifs.read(name, length);
    name[length] = '\0';
    ifs.read((char *)&length, sizeof(length));
    fn = new char[length + 1];
    ifs.read(fn, length);
    fn[length] = '\0';
    ifs.read((char *)&avg, sizeof(avg));
    ifs.read((char *)&group, sizeof(group));
}

void Student::clear()
{
    delete[] name;
    delete[] fn;
}

std::ostream &operator<<(std::ostream &os, const Student &S)
{
    return os << strlen(S.name) << ' '
              << S.name << ';'
              << strlen(S.fn) << ' '
              << S.fn << ';'
              << S.avg << ' '
              << S.group << '\n';
}

std::istream &operator>>(std::istream &is, Student &S)
{
    size_t length;
    is >> length;
    is.get();
    S.name = new char[length + 1];
    is.getline(S.name, length + 1, ';');
    is >> length;
    is.get();
    S.fn = new char[length + 1];
    is.getline(S.fn, length + 1, ';');
    is >> S.avg >> S.group;
    is.get();
    return is;
}

Student &Student::operator=(const Student &other)
{
    if (this != &other)
        copy(other);
    return *this;
}

Student::~Student()
{
    clear();
}

bool Student::operator<(const Student &other) const
{
    return avg < other.avg || (avg == other.avg && strcmp(fn, other.fn) < 0);
}
