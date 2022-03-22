#include <iostream>
#include "Store.hpp"

int main()
{
	Store a;
	Product p;
	p.read();
	std::cin.ignore();
	a.addProduct(p);
	p.read();
	std::cin.ignore();
	a.addProduct(p);
	p.read();
	std::cin.ignore();
	a.addProduct(p);
	p.read();
	std::cin.ignore();
	a.addProduct(p);
	a.print();
	a.printProducerGoods("az");
	std::cout << "Product you want to buy:\n";
	p.read();
	a.buy(p);
	a.print();
	return 0;
}