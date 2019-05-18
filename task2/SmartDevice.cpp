#include "SmartDevice.h"

SmartDevice::SmartDevice()
{
	setProductNumber(0);
	setRAM(0);
	setSpeed(0);
	setCores(0);
}

SmartDevice::SmartDevice(const SmartDevice &sd)
{
	setProductNumber(sd.getProductNumber());
	setRAM(sd.getRAM());
	setSpeed(sd.getSpeed());
	setCores(sd.getCores());
}

SmartDevice::SmartDevice(const int ProductNumber,const int RAM,
	const int Speed,const int Cores)
{
	setProductNumber(ProductNumber);
	setRAM(RAM);
	setSpeed(Speed);
	setCores(Cores);
}

void SmartDevice::setProductNumber(const int ProductNumber)
{
	this->ProductNumber = ProductNumber;
}

void SmartDevice::setRAM(const int RAM)
{
	this->RAM = RAM;
}

void SmartDevice::setSpeed(const int Speed)
{
	this->Speed = Speed;
}

void SmartDevice::setCores(const int Cores)
{
	this->Cores = Cores;
}

const int SmartDevice::getProductNumber() const
{
	return this->ProductNumber;
}

const int SmartDevice::getRAM() const
{
	return this->RAM;
}

const int SmartDevice::getSpeed() const
{
	return this->Speed;
}

const int SmartDevice::getCores() const
{
	return this->Cores;
}

void SmartDevice::Print() const
{
	cout << getProductNumber() << endl
		<< getRAM() << endl
		<< getSpeed() << endl
		<< getCores() << endl;
}
