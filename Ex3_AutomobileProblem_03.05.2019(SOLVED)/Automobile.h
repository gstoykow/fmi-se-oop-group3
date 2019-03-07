#pragma once
#include <string>
#include <iostream>
 
class Automobile
{

private:

	char* brand = nullptr;
	unsigned int type;
	unsigned int power;
	float price;

public:

	void setBrand(char* brand);
	char* getBrand() const;

	void setType(unsigned int type);
	unsigned int getType() const;

	void setPower(unsigned int power);
	unsigned int getPower() const;

	void setPrice(float price);
	float getPrice() const;

	void print() const;
	void comparePower(const Automobile& a);

	Automobile();
	Automobile(char* brand, unsigned int type, unsigned int power, float price);
	Automobile(const Automobile& a);
	~Automobile();

	//don`t worry we will learn about this
	Automobile& operator=(const Automobile& a);

};