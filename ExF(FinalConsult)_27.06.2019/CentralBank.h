#pragma once
#include <vector>

#include "ConcreteObserver.h"

using namespace std;

class CentralBank 
{

private:
	
	vector<string> currs;
	vector<double> rates;

	vector<Observer*> observers;

	const vector<string> getCurrs()const;
	const vector<double> getRates()const;

	void setCurrs(vector<string> currs);
	void setRates(vector<double> rates);

	void copyObservers(const CentralBank&);
	void deleteObservers();

public:

	void addCurrency(const string);
	void deleteCurrency(const string);
	void setRate(const string,double);

	void Register(Observer*);
	void Unregister(const unsigned int index);
	void notify(const string,double)const;

	CentralBank();
	CentralBank(const CentralBank&);
	CentralBank& operator=(const CentralBank&);
	~CentralBank();

};