#include "Product.hpp"

bool Product::copy(const Product &P)
{
	char *newName = new (std::nothrow) char[strlen(P.name) + 1];
	if (!newName)
	{
		std::cout << "<Product could not be copied properly.>\n";
		return false;
	}
	char *newPName = new (std::nothrow) char[strlen(P.producerName) + 1];
	if (!newPName)
	{
		delete[] newName;
		std::cout << "<Product could not be copied properly.>\n";
		return false;
	}
	strcpy(newName, P.name);
	strcpy(newPName, P.producerName);
	if (name)
		delete[] name;
	if (producerName)
		delete[] producerName;
	name = newName;
	producerName = newPName;
	price = P.price;
	quantity = P.quantity;
	std::cout << "<Product created successfully.>\n";
	return true;
}

Product::Product()
{
	name = producerName = nullptr;
	price = quantity = 0;
	std::cout << "<Product created successfully.>\n";
}

Product::Product(const char *_name, const char *_pName, unsigned _price, unsigned _quantity)
{

	name = producerName = nullptr;
	price = quantity = 0;
	char *newName = new (std::nothrow) char[strlen(_name) + 1];
	if (!newName)
	{
		std::cout << "<Product could not be created properly.>\n";
		return;
	}
	char *newPName = new (std::nothrow) char[strlen(_pName) + 1];
	if (!newPName)
	{
		std::cout << "<Product could not be created properly.>\n";
		return;
	}
	strcpy(newName, _name);
	strcpy(newPName, _pName);
	name = newName;
	producerName = newPName;
	price = _price;
	quantity = _quantity;
	std::cout << "<Product created successfully.>\n";
}

Product::Product(const Product &P)
{
	name = producerName = nullptr;
	copy(P);
	std::cout << "<Product created successfully.>\n";
}

bool Product::setName(const char *_name)
{
	char *newName = new (std::nothrow) char[strlen(_name) + 1];
	if (!newName)
	{
		std::cout << "<Name of Product could not be changed.>\n";
		return false;
	}
	strcpy(newName, _name);
	if (name)
		delete[] name;
	name = newName;
	std::cout << "<Name of Product changed successfully.>\n";
	return true;
}

bool Product::setProducerName(const char *_pName)
{
	char *newPName = new (std::nothrow) char[strlen(_pName) + 1];
	if (!newPName)
	{
		std::cout << "<ProducerName of Product could not be changed.>\n";
		return false;
	}
	strcpy(newPName, _pName);
	if (producerName)
		delete[] producerName;
	producerName = newPName;
	std::cout << "<ProducerName of Product changed successfully.>\n";
	return true;
}

bool Product::operator==(const Product &P) const
{
	return this == &P ||
		   ( // price == P.price &&
			 // quantity == P.quantity &&
			   !strcmp(name, P.name) &&
			   !strcmp(producerName, P.producerName));
}

const Product &Product::operator=(const Product &P)
{
	if (this != &P)
		copy(P);
	return *this;
}

void Product::print() const
{
	std::cout << "Name: " << (name ? name : " - ")
			  << "\tProducer: " << (producerName ? producerName : " - ")
			  << "\tPrice: " << price
			  << "\tQuantity: " << quantity << '\n';
}

Product::~Product()
{
	if (name)
		delete[] name;
	if (producerName)
		delete[] producerName;
	std::cout << "<Product deleted successfully.>\n";
}

bool Product::read()
{
	char bufName[INPUT_MAX], bufProducer[INPUT_MAX];
	std::cout << "Enter product's name: ";
	std::cin.getline(bufName, INPUT_MAX);
	char *newName = new (std::nothrow) char[strlen(bufName) + 1];
	if (!newName)
	{
		std::cout << "<Product could not be read.>\n";
		return false;
	}
	std::cout << "Enter producer's name: ";
	std::cin.getline(bufProducer, INPUT_MAX);
	char *newProducer = new (std::nothrow) char[strlen(bufProducer) + 1];
	if (!newProducer)
	{
		std::cout << "<Product could not be read.>\n";
		return false;
	}
	std::cout << "Enter product's price: ";
	std::cin >> price;
	std::cout << "Enter product's quantity: ";
	std::cin >> quantity;
	strcpy(newName, bufName);
	strcpy(newProducer, bufProducer);
	if (name)
		delete[] name;
	if (producerName)
		delete[] producerName;
	name = newName;
	producerName = newProducer;
	std::cout << "<Product read successfully.>\n";
	return true;
}
