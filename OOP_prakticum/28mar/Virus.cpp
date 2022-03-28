#include "Virus.hpp"

void Virus::copy(const Virus& other)
{
	clean();
	name = new (std::nothrow) char[strlen(other.name) + 1];
	assert(name);
	strcpy(name, other.name);
	severity = other.severity;
}

void Virus::clean()
{
	if (name)
		delete[] name;
}

void Virus::print(std::ostream& os) const
{
	os << "Name: " << (name ? name : " - ")
		<< "\tSeverity: " << severity << '\n';
}

Virus::Virus()
	:name(nullptr),severity(0)
{
}

Virus::Virus(const char* _name, unsigned _s)
	:name(new (std::nothrow) char[strlen(_name)+1]),severity(_s)
{
	assert(name);
	strcpy(name, _name);
}

Virus::Virus(const Virus& other)
	:name(nullptr)
{
	copy(other);
}

const Virus& Virus::operator=(const Virus& other)
{
	if (this != &other)
		copy(other);
	return *this;
}

void Virus::setName(const char* _name)
{
	if (name)delete[] name;
	name = new (std::nothrow) char[strlen(_name) + 1];
	assert(name);
	strcpy(name, _name);
}

void Virus::read(std::istream& is)
{
	clean();
	char input[INPUT_MAX];
	is.getline(input, INPUT_MAX);
	name = new (std::nothrow) char[strlen(input) + 1];
	assert(name);
	strcpy(name, input);
	is >> severity;
}

Virus::~Virus()
{
	clean();
}

std::istream& operator>>(std::istream& is, Virus& V)
{
	V.read(is);
	return is;
}

std::ostream& operator<<(std::ostream& os, const Virus& V)
{
	os << "Name: " << V.getName()
		<< "\tSeverity: " << V.getSeverity() << '\n';
	return os;
}
