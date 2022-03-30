#include "Test.hpp"

std::ostream& Test::operator<<(std::ostream& os)const
{
	return os << val << '\n';
}

const Test& Test::operator>>(std::istream& is)
{
	is >> val;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Test& T)
{
	return os << T.val << '\n';
}
