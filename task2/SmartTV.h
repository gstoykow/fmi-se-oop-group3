#pragma once

#include "SmartDevice.h"
#include "TV.h"

class SmartTV : public SmartDevice, public TV
{

private:

	int OSVersion = 0;

public:

	SmartTV();
	SmartTV(const int, const int, const int, const int, const char*, const int, const int, const int);
	SmartTV(const SmartTV&);
	SmartTV& operator=(const SmartTV&);
	~SmartTV() {}

	void setOSVersion(const int);
	const int getOSVersion()const;

	void Print()const;

};