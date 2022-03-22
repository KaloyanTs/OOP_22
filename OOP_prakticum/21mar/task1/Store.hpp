#ifndef __STORE_HPP
#define __STORE_HPP
#include "Product.hpp"
const unsigned INIT_CAPACITY = 1;

class Store
{
	size_t size;
	size_t capacity;
	Product **products;
	bool copy(const Store &S);
	void dealloc(Product **&arr, size_t size);
	bool resize(size_t newCapacity);
	bool addProductPointer(Product *ptr);

public:
	Store();
	Store(size_t _cap);
	Store(const Store &S);
	bool addProduct(const Product &P);
	bool addProduct(const char *_name, const char *_pName, unsigned _price, unsigned _quantity);
	void changeQuantity(const char *_name, const char *_pName, unsigned newQuantity);
	bool buy(const Product &P);
	size_t getCount() const { return size; }
	const Store &operator=(const Store &S);
	void print() const;
	void printProducerGoods(const char *producer) const;
	~Store();
};

#endif
