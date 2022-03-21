#include <iostream>
#include "Store.hpp"

int main()
{
	Store a;
	Product p;
	p.read();
	a.addProduct(p);
	p.read();
	a.addProduct(p);
	p.read();
	a.addProduct(p);
	p.read();
	a.addProduct(p);
	a.print();
	return 0;
}