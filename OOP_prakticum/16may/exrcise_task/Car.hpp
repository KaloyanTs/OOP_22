#ifndef __CAR_HPP
#define __CAR_HPP
#include <iostream>
#include <cstring>

class Car
{
	char* model;
	unsigned consumption;

	void clear();
protected:
	void copy(const Car& other);


public:
	Car(const char* m = "unknown", unsigned c = 0);
	virtual ~Car();
	Car(const Car& other);
	Car& operator=(const Car& other);

	const char* getModel()const { return model; }
	unsigned getConsumption()const { return consumption; }

	virtual void print(std::ostream& os = std::cout) const;
};

std::ostream& operator<<(std::ostream& os, const Car& C);


#endif
