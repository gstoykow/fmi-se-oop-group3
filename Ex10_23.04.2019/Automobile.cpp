#include "Automobile.h"

Automobile::Automobile()
{
	setBrand("Default");
	setHp(88);
}

Automobile::Automobile(const char * brand, const int hp)
{
	setBrand(brand);
	setHp(hp);
}

Automobile::Automobile(const Automobile & a)
{
	setBrand(a.getBrand());
	setHp(a.getHp());
}

Automobile::~Automobile()
{
	cout << "Automobile destructor called!";
	delete[] brand;
}

void Automobile::setBrand(const char * brand)
{
	delete[] this->brand;
	this->brand = new char[strlen(brand) + 1];
	strcpy_s(this->brand, strlen(brand) + 1, brand);
}

const char * Automobile::getBrand() const
{
	return this->brand;
}

void Automobile::setHp(const int hp)
{
	this->hp = hp;
}

const int Automobile::getHp() const
{
	return this->hp;
}
