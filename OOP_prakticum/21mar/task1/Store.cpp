#include "Store.hpp"

void Store::copy(const Store& S)
{
	Product** newArr = new(std::nothrow) Product * [S.capacity];
	if (!newArr)return;
	for (unsigned i = 0; i < size; ++i)
	{
		newArr[i] = new(std::nothrow) Product(*S.products[i]);
		if (!newArr[i]) {
			dealloc(newArr, i);
			return;
		}
	}
	capacity = S.capacity;
	size = S.size;
	dealloc(products, size);
	products = newArr;
	std::cout << "<Store copied successfully.>\n";
}

void Store::dealloc(Product** &arr, size_t size)
{
	for (unsigned i = 0; i < size; ++i)
		delete arr[i];
	delete[] arr;
	arr = nullptr;
}

Store::Store()
{
	size = 0;
	capacity = INIT_CAPACITY;
	products = new (std::nothrow) Product * [INIT_CAPACITY];
	assert(products);
	std::cout << "<Store created successfully.>\n";
}

Store::Store(size_t _cap)
{
	size = 0;
	capacity = _cap;
	products = new (std::nothrow) Product * [_cap];
	assert(products);
	std::cout << "<Store created successfully.>\n";
}

Store::Store(const Store& S)
{
	products = nullptr;
	copy(S);
	std::cout << "<Store created successfully.>\n";
}

void Store::addProduct(const Product& P)
{
	Product* newP = new(std::nothrow) Product(P);
	if (!newP)
	{
		std::cout << "<Product could not be added.>\n";
		return;
	}
	if(size==capacity)
	{
		Product** newArr = new(std::nothrow)Product * [2 * capacity];
		if (!newArr)
		{
			std::cout << "<Product could not be added.>\n";
			delete newP;
			return;
		}
		for (unsigned i = 0; i < size; ++i)
			newArr[i] = products[i];
		capacity *= 2;
	}
	products[size++] = newP;
	std::cout << "Product added successfully.\n";
}

void Store::addProduct(const char* _name, const char* _pName, unsigned _price, unsigned _quantity)
{
	Product* newP = new(std::nothrow) Product(_name,_pName,_price,_quantity);
	if (!newP)
	{
		std::cout << "<Product could not be added.>\n";
		return;
	}
	if (size == capacity)
	{
		Product** newArr = new(std::nothrow)Product * [2 * capacity];
		if (!newArr)
		{
			std::cout << "<Product could not be added.>\n";
			delete newP;
			return;
		}
		for (unsigned i = 0; i < size; ++i)
			newArr[i] = products[i];
		capacity *= 2;
	}
	products[size++] = newP;
	std::cout << "Product added successfully.\n";
}

void Store::changeQuantity(const char* _name, const char* _pName, unsigned newQuantity)
{
	unsigned i = 0;
	while (i < size &&
		  (strcmp(products[i]->getName(), _name)
		  || strcmp(products[i]->getProducerName(), _pName)))
		++i;
	if (i < size)
		products[i]->setQuantity(newQuantity);
}

void Store::buy(const Product& P)
{
	unsigned i = 0;
	while (i < size && !(*products[i] == P))
		++i;
	if (i == size || !products[i]->getQuantity())
	{
		std::cout << "<Product not available.>\n";
		return;
	}
	std::cout << "You bought: ";
	products[i]->print();
	delete products[i];
	for (unsigned j = i; j < size - 1; ++j)
		products[i] = products[i + 1];
	--size;
}

const Store& Store::operator=(const Store& S)
{
	if (this != &S)
		copy(S);
	return *this;
}

void Store::print() const
{
	for (unsigned i = 0; i < size; ++i)
	{
		std::cout << i + 1 << ": ";
		products[i]->print();
	}
}

void Store::printProducerGoods(const char* producer) const
{
	unsigned j = 0;
	for(unsigned i=0;i<size;++i)
		if (!strcmp(products[i]->getProducerName(), producer))
		{
			std::cout << ++j << ": ";
			products[i]->print();
		}
}

Store::~Store()
{
	dealloc(products, size);
}
