#ifndef __STORE_HPP
#define __STORE_HPP
#include "Product.hpp"
const unsigned INIT_CAPACITY = 1;

class Store {
	size_t size;
	size_t capacity;
	Product** products;
	void copy(const Store& S);
	void dealloc(Product** &arr, size_t size);
public:
	Store();
	Store(size_t _cap);
	Store(const Store& S);
	void addProduct(const Product&P);
	void addProduct(const char* _name, const char* _pName, unsigned _price, unsigned _quantity);
	void changeQuantity(const char* _name, const char* _pName, unsigned newQuantity);
	void buy(const Product& P);
	size_t getCount()const { return size; }
	const Store& operator=(const Store& S);
	void print()const;
	void printProducerGoods(const char* producer)const;
	~Store();

};

#endif
