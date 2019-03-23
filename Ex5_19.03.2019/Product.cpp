#include "Product.h"

unsigned int SKU = 0;

unsigned int Product::getSKU() const
{
	return this->currSKU;
}

void Product::incrementSKU()
{
	this->currSKU = SKU;
	SKU++;
}

char * Product::getBrand() const
{
	return this->brand;
}

void Product::setBrand(const char* brand)
{
	this->brand = new char[strlen(brand) + 1];
	strcpy_s(this->brand, strlen(brand) + 1, brand);
}

char * Product::getModel() const
{
	return this->model;
}

void Product::setModel(const char* model)
{
	this->model = new char[strlen(model) + 1];
	strcpy_s(this->model, strlen(model) + 1, model);
}

unsigned int Product::getPrice() const
{
	return this->price;
}

void Product::setPrice(unsigned int price)
{
	this->price = price;
}

unsigned int Product::getCount() const
{
	return this->count;
}

void Product::setCount(unsigned int count)
{
	this->count = count;
}

void Product::print() const
{
	cout << "Prod. SKU: " << getSKU() << endl
		<< "Prod. brand: " << getBrand() << endl
		<< "Prod. model: " << getModel() << endl
		<< "Prod. price: " << getPrice() << endl
		<< "Prod. count: " << getCount() << endl<<endl;
}

Product::Product()
{
	incrementSKU();
	setBrand("def");
	setModel("def");
	setPrice(1);
	setCount(1);
}

Product::Product(const char * brand, const char * model, unsigned int price, unsigned int count)
{
	incrementSKU();
	setBrand(brand);
	setModel(model);
	setPrice(price);
	setCount(count);
}

Product::Product(const Product &p)
{
	incrementSKU();
	setBrand(p.brand);
	setModel(p.model);
	setPrice(p.price);
	setCount(p.count);
}

Product::~Product()
{
	delete[] brand;
	delete[] model;
}
