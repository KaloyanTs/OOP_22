#include <iostream>
#include "AmortizedCar.hpp"


int main()
{
	AmortizedCar c("dfdfs", 65, "fdfsfdf",10);
	std::cout << c << '\n';

	Car* arr[] =
	{
		new Car,
		new TuningCar,
		new AmortizedCar
	};

	for (unsigned i = 0; i < 3; ++i)
		std::cout << *arr[i] << '\n';

	for (unsigned i = 0; i < 3; ++i)
		delete arr[i];

	return 0;
}