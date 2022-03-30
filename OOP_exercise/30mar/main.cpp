#include <iostream>
#include "Test.hpp"
#include "String.hpp"

int main()
{
	Test a;
	a >> std::cin << std::cout << a;
	String s;
	std::cin.ignore();
	std::cin >> s;
	s = s + s;
	std::cout << s << '\n';
	return 0;
}