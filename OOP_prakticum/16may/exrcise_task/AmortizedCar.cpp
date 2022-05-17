#include "AmortizedCar.hpp"

AmortizedCar::AmortizedCar(const char* model, unsigned c, const char* cmp, unsigned inc)
	:TuningCar(model,c,cmp),increasing(inc)
{
}

void AmortizedCar::print(std::ostream& os) const
{
	TuningCar::print(os);
	os << "\nConsumption increased to " << getConsumption() + increasing << '.';
}
