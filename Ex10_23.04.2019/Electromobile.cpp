#include "Electromobile.h"

Electromobile::~Electromobile() 
{
	cout << "Electromobile destructor called!";
	delete[] batteryModel;
}

void Electromobile::setBatteryModel(const char * batteryModel)
{
	delete[] this->batteryModel;
	this->batteryModel = new char[strlen(batteryModel) + 1];
	strcpy_s(this->batteryModel, strlen(batteryModel) + 1, batteryModel);
}

const char * Electromobile::getBatteryModel() const
{
	return this->batteryModel;
}
