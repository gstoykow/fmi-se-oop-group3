#pragma once
#include <string.h>
#include <iostream>
using namespace std;

class Automobile
{

private:

	char* brand = nullptr;
	int hp;

public:

	Automobile();
	Automobile(const char* brand, const int hp);
	Automobile(const Automobile& a);
	~Automobile();

	void setBrand(const char* brand);
	const char* getBrand()const;

	void setHp(const int hp);
	const int getHp()const;

};