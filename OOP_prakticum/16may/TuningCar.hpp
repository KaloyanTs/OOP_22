#ifndef __TUNINGCAR_HPP
#define __TUNINGCAR_HPP
#include "Car.hpp"

class TuningCar:public Car
{
	char* company;

	void copy(const TuningCar& other);
	void clear();

public:
	TuningCar(const char* model = "unknown", unsigned c = 0, const char* cmp = "unknown");
	TuningCar(const TuningCar& other);
	~TuningCar();
	TuningCar& operator=(const TuningCar& other);

	const char* getCompany()const { return company; }

	void print(std::ostream& os = std::cout) const override;

};

#endif