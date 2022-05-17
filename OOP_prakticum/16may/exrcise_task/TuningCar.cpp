#include "TuningCar.hpp"

void TuningCar::copy(const TuningCar& other)
{
	Car::copy(other);
	clear();
	company = new char[strlen(other.company) + 1];
	strcpy(company, other.company);
}

void TuningCar::clear()
{
	delete[] company;
}

TuningCar::TuningCar(const char* model, unsigned c, const char* cmp)
	:Car(model,c),company(new char[strlen(cmp)+1])
{
	strcpy(company, cmp);
}

TuningCar::TuningCar(const TuningCar& other)
	:Car(other)
{
	copy(other);
}

TuningCar::~TuningCar()
{
	clear();
}

TuningCar& TuningCar::operator=(const TuningCar& other)
{
	if (this != &other)
	{
		Car::copy(other);
		//(Car*)this->copy((const Car &)other);
		copy(other);
	}
	return *this;
}

void TuningCar::print(std::ostream& os) const
{
	Car::print(os);
	os << "\nby " << company;
}
