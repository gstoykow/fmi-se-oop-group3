#include "CentralBank.h"

const vector<string> CentralBank::getCurrs() const
{
	return this->currs;
}

const vector<double> CentralBank::getRates() const
{
	return this->rates;
}

void CentralBank::setCurrs(vector<string> currs)
{
	this->currs = currs;
}

void CentralBank::setRates(vector<double> rates)
{
	this->rates = rates;
}

void CentralBank::copyObservers(const CentralBank &cb)
{
	if (this != &cb)
	{
		for (int i = 0; i < cb.observers.size(); i++)
		{
			this->observers.push_back(cb.observers[i]->clone());
		}
	}
}

void CentralBank::deleteObservers()
{
	for (int i = 0; i < observers.size(); i++)
	{
		delete observers[i];
	}
	observers.clear();
}

void CentralBank::addCurrency(const string name)
{
	currs.push_back(name);
	rates.push_back(0);

	notify(name, 0);
}

void CentralBank::deleteCurrency(const string name)
{
	for (int i = 0; i < currs.size(); i++)
	{
		if (currs[i] == name)
		{
			currs.erase(currs.begin() + i);
			rates.erase(rates.begin() + i);
		}
	}
}

void CentralBank::setRate(const string name, double rate)
{
	for (int i = 0; i < currs.size(); i++)
	{
		if (currs[i] == name)
		{
			rates[i] = rate;
			notify(name, rate);
		}
	}
}

void CentralBank::Register(Observer* o)
{
	observers.push_back(o);
}

void CentralBank::Unregister(const unsigned int index)
{
	if (index >= observers.size())
		return;
	else
	{	
		delete observers[index];
		observers.erase(observers.begin() + index);
	}
}

void CentralBank::notify(const string currency, double rate) const
{
	for (int i = 0; i < observers.size(); i++)
	{
		observers[i]->update(currency,rate);
	}
}

CentralBank::CentralBank()
{

}

CentralBank::CentralBank(const CentralBank &cb)
{
	setCurrs(cb.getCurrs());
	setRates(cb.getRates());

	copyObservers(cb);
}

CentralBank & CentralBank::operator=(const CentralBank &cb)
{
	deleteObservers();

	setCurrs(cb.getCurrs());
	setRates(cb.getRates());

	copyObservers(cb);

	return *this;
}

CentralBank::~CentralBank()
{
	deleteObservers();
}
