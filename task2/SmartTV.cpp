#include "SmartTV.h"

SmartTV::SmartTV() : TV() , SmartDevice()
{
	setOSVersion(0);
}

SmartTV::SmartTV(const int ProductNumber,const int RAM,const int Speed,
	const int Cores, const char * Name,
	const int Width,const int Height,const int OSVersion) : SmartDevice(ProductNumber,RAM,Speed,Cores), TV(Name,Width,Height)
{
	setOSVersion(OSVersion);
}

SmartTV::SmartTV(const SmartTV &stv)
{
	*this = stv;
}

SmartTV & SmartTV::operator=(const SmartTV &stv)
{
	setProductNumber(stv.getProductNumber());
	setRAM(stv.getRAM());
	setSpeed(stv.getSpeed());
	setName(stv.getName());
	setWidth(stv.getWidth());
	setHeight(stv.getHeight());
	setOSVersion(stv.getOSVersion());

	return *this;
}

void SmartTV::setOSVersion(const int OSVersion)
{
	this->OSVersion = OSVersion;
}

const int SmartTV::getOSVersion() const
{
	return this->OSVersion;
}

void SmartTV::Print() const
{
	TV::Print();
	SmartDevice::Print();
	cout << getOSVersion();
	cout << endl;
}
