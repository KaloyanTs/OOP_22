#include "Auto.hpp"

void Auto::copy(const Auto &other)
{
    delete[] id;
    delete[] model;
    delete[] owner;
    year = other.year;
    if (other.id)
    {
        id = new (std::nothrow) char[strlen(other.id) + 1];
        assert(id);
        strcpy(id, other.id);
    }
    if (other.model)
    {
        model = new (std::nothrow) char[strlen(other.model) + 1];
        assert(model);
        strcpy(model, other.model);
    }
    if (other.owner)
    {
        owner = new (std::nothrow) char[strlen(other.owner) + 1];
        assert(owner);
        strcpy(owner, other.owner);
    }
}

Auto::Auto(const Auto &other)
    : id(nullptr), model(nullptr), owner(nullptr)
{
    copy(other);
}

Auto &Auto::operator=(const Auto &other)
{
    if (this != &other)
        copy(other);
    return *this;
}

std::ostream &Auto::print(std::ostream &os) const
{
    return os << "ID: " << (id ? id : NOT_INIT_MESSAGE)
              << ":\t" << (model ? model : NOT_INIT_MESSAGE)
              << ' ' << year
              << '\t' << (owner ? owner : NOT_INIT_MESSAGE) << '\n';
}

Auto::~Auto()
{
    clean();
}

Auto::Auto(const char *_id, const char *_m, unsigned _year, const char *_owner)
    : id(new (std::nothrow) char[strlen(_id) + 1]),
      model(new (std::nothrow) char[strlen(_m) + 1]),
      owner(new (std::nothrow) char[strlen(_owner) + 1]),
      year(_year)
{
    assert(id && model && owner);
    strcpy(id, _id);
    strcpy(model, _m);
    strcpy(owner, _owner);
}

std::ostream &operator<<(std::ostream &os, const Auto &A)
{
    return A.print(os);
}

std::istream &operator>>(std::istream &is, Auto &A)
{
    A.clean();
    char buf[INPUT_MAX];
    is.getline(buf, INPUT_MAX);
    A.id = new (std::nothrow) char[strlen(buf) + 1];
    assert(A.id);
    strcpy(A.id, buf);
    is.getline(buf, INPUT_MAX);
    A.model = new (std::nothrow) char[strlen(buf) + 1];
    assert(A.model);
    strcpy(A.model, buf);
    is >> A.year;
    is.ignore();
    is.getline(buf, INPUT_MAX);
    A.owner = new (std::nothrow) char[strlen(buf) + 1];
    assert(A.owner);
    strcpy(A.owner, buf);
    return is;
}
void Auto::clean()
{
    delete[] id;
    delete[] model;
    delete[] owner;
}
