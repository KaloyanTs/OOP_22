#include "GP.hpp"

void GP::clear()
{
    for (unsigned i = 0; i < size; ++i)
        delete patients[i];
    delete[] patients;
}

void GP::copy(const GP &other)
{
    clear();
    size = other.size;
    capacity = other.capacity;
    patients = new Patient *[capacity];
    for (unsigned i = 0; i < size; ++i)
        patients[i] = new Patient(*other.patients[i]);
}

GP::GP(const GP &other)
    : patients(nullptr)
{
    copy(other);
}

GP &GP::operator=(const GP &other)
{
    if (this != &other)
        copy(other);
    return *this;
}

GP::~GP()
{
    clear();
}

GP &GP::addPatient(const Patient &P)
{
    if (size == capacity)
        resize(2 * capacity);
    patients[size++] = new Patient(P);
    return *this;
}

GP &GP::removePatient(const char *name)
{
    unsigned pos{0};
    while (pos < size && strcmp(patients[pos]->getName(), name))
        ++pos;
    if (pos == size)
        return *this;
    delete patients[pos];
    for (unsigned j = pos; j < size - 1; ++j)
        patients[j] = patients[j + 1];
    --size;
    return *this;
}

GP &GP::printDiagnosed(const char *diagnose)
{
    std::cout << "With diagnose: " << diagnose << '\n';
    for (unsigned i = 0; i < size; ++i)
        if (patients[i]->hasDignose(diagnose))
            std::cout << '\t' << *patients[i];
    return *this;
}

GP &GP::sortByAge()
{
    unsigned iMax{0};
    Patient *tmp{nullptr};
    for (unsigned i = 0; i < size - 1; ++i)
    {
        iMax = i;
        for (unsigned j = i + 1; j < size; ++j)
            if (patients[j]->getAge() > patients[iMax]->getAge())
                iMax = j;
        tmp = patients[i];
        patients[i] = patients[iMax];
        patients[iMax] = tmp;
    }
    return *this;
}

GP GP::operator+(const Patient &P)
{
    GP tmp = *this;
    return tmp += P;
}

GP GP::operator-(const char *name)
{
    GP tmp = *this;
    return tmp -= name;
}

void GP::showAverageCondition() const
{
    float avg = 0;
    for (unsigned i = 0; i < size; ++i)
        avg += patients[i]->getConditionScore();
    std::cout << "Average condition (1 - 10): " << avg / size << '\n';
}

void GP::resize(size_t newCap)
{
    assert(newCap >= capacity);
    capacity = newCap;
    Patient **newArr = new Patient *[capacity];
    for (unsigned i = 0; i < size; ++i)
        newArr[i] = patients[i];
    delete[] patients;
    patients = newArr;
}

void GP::writeToBinary(const char *fileName)
{
    std::ofstream ofs(fileName, std::ios::binary);
    assert(ofs.is_open());
    ofs.write((const char *)&size, sizeof(size));
    for (unsigned i = 0; i < size; ++i)
        patients[i]->writeToBinary(ofs);
    ofs.close();
}

void GP::readFromBinary(const char *fileName)
{
    clear();
    std::ifstream ifs(fileName, std::ios::binary);
    assert(ifs.is_open());
    ifs.read((char *)&size, sizeof(size));
    capacity = size;
    patients = new Patient *[capacity];
    for (unsigned i = 0; i < size; ++i)
    {
        patients[i] = new Patient;
        patients[i]->readFromBinary(ifs);
    }
    ifs.close();
}

GP::GP(size_t _c)
    : patients(new Patient *[_c]), size(0), capacity(_c)
{
}

void GP::print() const
{
    std::cout << size << '\n';
    for (unsigned i = 0; i < size; ++i)
        std::cout << *patients[i];
}
