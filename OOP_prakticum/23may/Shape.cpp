#include "Shape.hpp"

std::ostream& operator<<(std::ostream& os, const Shape& f)
{
	f.print(os);
	return os;
}
