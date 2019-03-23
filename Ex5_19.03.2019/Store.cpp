#include "Store.h"

void Store::increaseSsize()
{
	this->ssize++;
}

void Store::decreaseSsize()
{
	if (getSsize() > 0)
	this->ssize--;
}

void Store::increaseScap()
{
	if (this->scap == 0)
	{
		this->scap = 2;
	}
	else
	{
		this->scap *= 2;
	}
}

int Store::getScap() const
{
	return this->scap;
}

void Store::resize()
{
	increaseScap();
	Product** newProducts = new Product*[getScap];

	for (int i = 0; i < getSsize(); i++)
	{
		newProducts[i] = products[i];
	}

	delete[] products;
	products = newProducts;
}

int Store::getSsize() const
{
	return this->ssize;
}

void Store::addProduct(const Product &p)
{
	if (getSsize() == getScap())resize();

	increaseSsize();

	products[getSsize() - 1] =
		new Product(p.getBrand(), p.getModel(), p.getPrice(), p.getCount());
}

bool Store::removeProduct(unsigned int index)
{
	if (index >= getSsize())
		return 0;
	else
	{
		delete products[index];
		for (int i = index; i < getSsize() - 1; i++)
		{
			products[i] = products[i + 1];
		}
		decreaseSsize();
		return 1;
	}
}

bool Store::changeProduct(unsigned int index, const Product& p)
{
	if (index >= getSsize())
		return 0;
	else
	{
		delete products[index];
		products[index] =
			new Product(p.getBrand(), p.getModel(), p.getPrice(), p.getCount());
		return 1;
	}
}

void Store::printStore() const
{
	for (int i = 0; i < getSsize(); i++)
	{
		products[i]->print();
	}
}

Store::~Store()
{
	for (int i = 0; i < getSsize(); i++)
	{
		delete products[i];
	}
	delete[] products;
}
