#ifndef __PRODUCT_HPP
#define __PRODUCT_HPP
#include <iostream>
#include <cstring>
#include <cassert>
const unsigned INPUT_MAX = 16;

class Product
{
	char *name;
	char *producerName;
	unsigned price;
	unsigned quantity;
	bool copy(const Product &P);

public:
	Product();
	Product(const char *_name, const char *_pName, unsigned _price, unsigned _quantity);
	Product(const Product &P);
	bool read();
	const char *getName() const { return name; }
	bool setName(const char *_name);
	const char *getProducerName() const { return producerName; }
	bool setProducerName(const char *);
	unsigned getPrice() const { return price; }
	void setPrice(unsigned _price) { price = _price; }
	unsigned getQuantity() const { return quantity; }
	void setQuantity(unsigned _quantity) { quantity = _quantity; }
	bool operator==(const Product &P) const;
	const Product &operator=(const Product &P);
	void print() const;
	~Product();
};

#endif
