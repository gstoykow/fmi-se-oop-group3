#include "Automobile.h"

using namespace std;

void Automobile::setBrand(char* brand)
{
	if (brand != nullptr && brand[0] != '\0')
	{
		this->brand = new char[strlen(brand) + 1];
		strcpy_s(this->brand, strlen(brand) + 1, brand);
	}
}

char * Automobile::getBrand() const
{
	return this->brand;
}

void Automobile::setType(unsigned int type)
{
	if (type == 1 || type == 2 || type == 3)
	{
		this->type = type;
	}
}

unsigned int Automobile::getType() const
{
	return this->type;
}

void Automobile::setPower(unsigned int power)
{
	this->power = power;
}

unsigned int Automobile::getPower() const
{
	return this->power;
}

void Automobile::setPrice(float price)
{
	if (price > 0)
	{
		this->price = price;
	}
}

float Automobile::getPrice() const
{
	return this->price;
}

void Automobile::print() const
{
	cout << "Brand: " << this->getBrand() << endl
		<< "Type: " << this->getType() << endl
		<< "Power: " << this->getPower() << endl
		<< "Price: " << this->getPrice() << endl<<endl;
}

void Automobile::comparePower(const Automobile & a)
{
	if (this->power > a.getPower())
	{
		print();
	}
	else a.print();
}

Automobile::Automobile()
{
	setBrand("Default");
	setType(1);
	setPower(1);
	setPrice(1);
}

Automobile::Automobile(char* brand, unsigned int type, unsigned int power, float price)
{
	setBrand(brand);
	setType(type);
	setPower(power);
	setPrice(price);
}

Automobile::Automobile(const Automobile & a)
{
	setBrand(a.brand);
	setType(a.type);
	setPower(a.power);
	setPrice(a.price);
}

Automobile::~Automobile()
{
	delete[] brand;
}

//don`t worry we will learn about this
Automobile & Automobile::operator=(const Automobile & a)
{
	setBrand(a.brand);
	setType(a.type);
	setPower(a.power);
	setPrice(a.price);
	return *this;
}
