#pragma once

#include <iostream>

using namespace std;


class SmartDevice 
{

private:

	int ProductNumber = 0;
	int RAM = 0;
	int Speed = 0;
	int Cores = 0;

public:

	SmartDevice();
	SmartDevice(const SmartDevice&);
	SmartDevice(const int, const int, const int, const int);

	void setProductNumber(const int);
	void setRAM(const int);
	void setSpeed(const int);
	void setCores(const int);

	const int getProductNumber()const;
	const int getRAM()const;
	const int getSpeed()const;
	const int getCores()const;

	void Print()const;



};