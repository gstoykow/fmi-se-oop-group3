#pragma once
#include <string>
#include <iostream>

using namespace std;

class Observer 
{

public:

	virtual void update(const string, double)const = 0;
	virtual Observer* clone()const = 0;

};