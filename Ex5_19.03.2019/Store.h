#pragma once
#include "Product.h"

class Store
{

private:

	Product** products;
	int ssize = 0;
	int scap = 0;

	void increaseSsize();
	void decreaseSsize();

	void increaseScap();
	int getScap()const;

	void resize();

public:
	int getSsize()const;

	void addProduct(const Product&);
	bool removeProduct(unsigned int);
	bool changeProduct(unsigned int, const Product&);
	void printStore()const;

	~Store();

};
