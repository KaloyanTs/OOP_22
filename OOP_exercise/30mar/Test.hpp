#ifndef __TEST_HPP
#define __TEST_HPP
#include <iostream>

class Test
{
	int val;
public:
	Test(int _v = 5) :val(_v) {}
	std::ostream& operator<<(std::ostream& os)const;
	friend std::ostream& operator<<(std::ostream&, const Test&);
	const Test& operator>>(std::istream&);
};



#endif