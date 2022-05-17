#ifndef __AMORTIZEDCAR_HPP
#define __AMORTIZEDCAR_HPP
#include "TuningCar.hpp"

class AmortizedCar:public TuningCar
{
	unsigned increasing;
public:

	AmortizedCar(const char* model = "unknown", unsigned c=0, const char* cmp="unknown", unsigned inc = 0);

	void print(std::ostream& os = std::cout)const;
};

#endif
