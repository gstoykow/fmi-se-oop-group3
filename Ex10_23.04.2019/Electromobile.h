#pragma once
#include "Automobile.h"


class Electromobile : public Automobile
{

private:

	char* batteryModel;

public:

	Electromobile() : Automobile() 
	{
		setBatteryModel("Default");
	}

	Electromobile(const char* brand, const int hp, const char* batteryModel) :
		Automobile(brand, hp) 
	{
		setBatteryModel(batteryModel);
	}

	Electromobile(const Electromobile& e) : Automobile(e.getBrand(), e.getHp())
	{
		setBatteryModel(e.getBatteryModel());
	}

	~Electromobile();

	void setBatteryModel(const char* batteryModel);
	const char* getBatteryModel()const;

};