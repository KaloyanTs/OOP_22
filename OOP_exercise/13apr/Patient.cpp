#include "Patient.hpp"

Patient::Patient(const char *_name,
                 const char *_address,
                 unsigned _age,
                 const char *_diag,
                 Condition _c,
                 float _good)
    : name(new char[strlen(_name) + 1]),
      age(_age),
      condition(_c),
      good(_good),
      diagnose(new char[strlen(_diag) + 1])
{
    assert(good >= 1 && good <= 10);
    strncpy(address, _address, ADDRESS_MAX);
    address[ADDRESS_MAX] = '\0';
    strcpy(name, _name);
    strcpy(diagnose, _diag);
}

void Patient::clear()
{
    delete[] name;
    delete[] diagnose;
}

void Patient::copy(const Patient &other)
{
    clear();
    age = other.age;
    condition = other.condition;
    good = other.good;
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    diagnose = new char[strlen(other.diagnose) + 1];
    strcpy(diagnose, other.diagnose);
    strcpy(address, other.address);
}

Patient::Patient(const Patient &other)
    : name(nullptr), diagnose(nullptr)
{
    copy(other);
}

Patient &Patient::operator=(const Patient &other)
{
    if (this != &other)
        copy(other);
    return *this;
}

Patient::~Patient()
{
    clear();
}

void Patient::setDiagnose(const char *newDiag)
{
    delete[] diagnose;
    diagnose = new char[strlen(newDiag) + 1];
    strcpy(diagnose, newDiag);
}

void Patient::setCodition(Condition newCond)
{
    condition = newCond;
}

std::ostream &operator<<(std::ostream &os, const Patient &P)
{
    if (&os == &std::cout)
        os << "Name: ";
    return os << P.name
              << (&os == &std::cout, "\nAge: ", ',') << P.age
              << (&os == &std::cout, "\nAddress: ", ',') << P.address
              << (&os == &std::cout, "\nDiagnose: ", ',') << P.diagnose
              << (&os == &std::cout, "\nCondition: ", ',') << P.condition
              << (&os == &std::cout, "\nCondition score: ", ',') << P.good << '\n';
}

std::istream &operator>>(std::istream &is, Patient &P)
{
    P.clear();
    char buf[INPUT_MAX + 1];
    is.getline(buf, INPUT_MAX);
    P.name = new char[strlen(buf) + 1];
    strcpy(P.name, buf);
    is >> P.age;
    is.get();
    is.getline(buf, INPUT_MAX);
    strncpy(P.address, buf, ADDRESS_MAX);
    is.getline(buf, INPUT_MAX);
    P.diagnose = new char[strlen(buf) + 1];
    strcpy(P.diagnose, buf);
    is >> P.condition;
    is >> P.good;
    assert(P.good >= 1 && P.good <= 10);
    is.get();
    return is;
}

std::ostream &operator<<(std::ostream &os, Condition C)
{
    switch (C)
    {
    case HEALTHY:
        return os << "healthy";
    case ILL:
        return os << "bad";
    case SERIOUSLY_ILL:
        return os << "seriously bad";
    case HEALING:
        return os << "healing";
    default:
        return os << "unknown";
    }
}

std::istream &operator>>(std::istream &is, Condition &C)
{
    char buf[INPUT_MAX];
    if (&is != &std::cin)
        is.getline(buf, INPUT_MAX, ',');
    else
        is.getline(buf, INPUT_MAX);
    if (!strcmp(buf, "healing"))
        C = HEALING;
    else if (!strcmp(buf, "bad"))
        C = ILL;
    if (!strcmp(buf, "seriously bad"))
        C = SERIOUSLY_ILL;
    else
        C = HEALTHY;
    return is;
}

void Patient::writeToBinary(std::ofstream &ofs)
{
    size_t length = strlen(name);

    ofs.write((const char *)&length, sizeof(length));
    ofs.write(name, length);
    ofs.write((const char *)&age, sizeof(age));
    ofs.write(address, ADDRESS_MAX);
    length = strlen(diagnose);
    ofs.write((const char *)&length, sizeof(length));
    ofs.write(diagnose, length);
    ofs.write((const char *)&condition, sizeof(condition));
    ofs.write((const char *)&good, sizeof(good));
}

void Patient::readFromBinary(std::ifstream &ifs)
{
    clear();
    size_t length;
    ifs.read((char *)&length, sizeof(length));
    name = new char[length + 1];
    ifs.read(name, length);
    name[length] = '\0';
    ifs.read((char *)&age, sizeof(age));
    ifs.read(address, ADDRESS_MAX);
    ifs.read((char *)&length, sizeof(length));
    diagnose = new char[length + 1];
    ifs.read(diagnose, length);
    diagnose[length] = '\0';
    ifs.read((char *)&condition, sizeof(condition));
    ifs.read((char *)&good, sizeof(good));
}

void Patient::writeToText(std::ofstream &ofs)
{
    ofs << strlen(name) << ',' << name
        << ',' << age
        << ',' << address
        << ',' << strlen(diagnose)
        << ',' << diagnose
        << ',' << condition
        << ',' << good << '\n';
}

void Patient::readFromText(std::ifstream &ifs)
{
    clear();
    size_t length;
    ifs >> length;
    ifs.get();
    name = new char[length + 1];
    ifs.getline(name, length + 1, ',');
    ifs >> age;
    ifs.get();
    ifs.getline(address, ADDRESS_MAX, ',');
    ifs >> length;
    ifs.get();
    diagnose = new char[length + 1];
    ifs.getline(diagnose, length + 1, ',');
    ifs >> condition >> good;
}
