#include "ConcreteObserver.h"

const string ConcreteObserver::getName() const
{
	return this->name;
}

void ConcreteObserver::setName(const string name)
{
	this->name = name;
}

ConcreteObserver::ConcreteObserver()
{
	setName("madafaka");
}

ConcreteObserver::ConcreteObserver(const string name)
{
	setName(name);
}

ConcreteObserver::ConcreteObserver(const ConcreteObserver &co)
{
	setName(co.getName());
}

ConcreteObserver & ConcreteObserver::operator=(const ConcreteObserver &co)
{
	if (this != &co)
	{
		setName(co.getName());
	}

	return *this;
}

void ConcreteObserver::update(const string currency, double rate) const
{
	cout <<"Update "<< getName() << ":"
		<< currency << " "
		<< rate << endl;
}

Observer * ConcreteObserver::clone() const 
{
	return new ConcreteObserver(*this);
}

