#pragma once
#include "Automobile.h"

class Dealer
{

private:

	char* name = nullptr;
	Automobile** automobiles;
	int size;
	int cap;

public:

	Dealer();
	Dealer(char* name, Automobile** automobiles);
	Dealer(const Dealer& d);
	~Dealer();

	void setName(char* name);
	char* getName()const;

	void addAutomobile(const Automobile& a);
	bool removeAutomobile(int index);
	Automobile& getAutomobile(int index);

	void setSize(int size);
	int getSize()const;

	void setCap(int cap);
	int getCap()const;


};