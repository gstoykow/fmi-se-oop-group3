#pragma once
#include "Observer.h"

class ConcreteObserver : public Observer
{

private:

	string name;

public:

	const string getName()const;
	void setName(const string);

	ConcreteObserver();
	ConcreteObserver(const string name);
	ConcreteObserver(const ConcreteObserver&);
	ConcreteObserver& operator=(const ConcreteObserver&);

	void update(const string, double)const override;
	Observer* clone()const override;

};