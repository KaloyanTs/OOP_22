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
	a.buy("apple", "az", 5, 2);
	a.print();
	return 0;
}