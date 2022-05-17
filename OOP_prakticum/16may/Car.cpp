#include "Car.hpp"

void Car::clear()
{
	delete[]model;
}

void Car::copy(const Car& other)
{
	clear();
	model = new char[strlen(other.model) + 1];
	strcpy(model, other.model);
	consumption = other.consumption;
}

Car::Car(const char* m, unsigned c)
:model(new char[strlen(m)+1]),consumption(c)
{
	strcpy(model, m);
}

Car::~Car()
{
	clear();
}

Car::Car(const Car& other)
	:model(nullptr)
{
	copy(other);
}

Car& Car::operator=(const Car& other)
{
	if(this != &other)
		copy(other);
	return *this;
}

void Car::print(std::ostream& os) const
{
	os << "Model: " << model << "\tConsumption: " << consumption;
}

std::ostream& operator<<(std::ostream& os, const Car& C)
{
	C.print(os);
	return os;
}
