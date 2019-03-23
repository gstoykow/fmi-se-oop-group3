#pragma once
#include <iostream>

using namespace std;

extern unsigned int SKU;

class Product
{

private:

	unsigned int currSKU;
	char* brand = nullptr;
	char* model = nullptr;
	unsigned int price;
	unsigned int count;

public:

	unsigned int getSKU()const;
	void incrementSKU();

	char* getBrand()const;
	void setBrand(const char*);

	char* getModel()const;
	void setModel(const char*);

	unsigned int getPrice()const;
	void setPrice(unsigned int);

	unsigned int getCount()const;
	void setCount(unsigned int);

	void print()const;

	Product();
	Product(const char*, const char*, unsigned int, unsigned int);
	Product(const Product&);
	~Product();

};
