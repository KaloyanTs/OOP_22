#include <iostream>
#include "Time.hpp"

int main()
{
	Time t1, t2, t3;
	std::cin >> t1 >> t2;
	t3 = t1 + t2;
	std::cout << t3 << '\n';
	t2=t1 + 5;
	std::cout << t2 << '\n';
	t3 = 6 + t1;
	std::cout << t3 << '\n';
	return 0;
}