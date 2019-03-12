#include "Dealer.h"

Dealer::Dealer()
{
}

Dealer::Dealer(char * name, Automobile ** automobiles)
{
}

Dealer::Dealer(const Dealer & d)
{
}

Dealer::~Dealer()
{
}

void Dealer::setName(char * name)
{
	this->name = new char[strlen(name)+1];
	strcpy_s(this->name, strlen(name)+1, name);
}

char * Dealer::getName() const
{
	return this->name;
}

void Dealer::addAutomobile(const Automobile & a)
{
	if (size + 1 >= getCap())
	{
		setCap(getCap()* 2);
		Automobile** newAutomobiles = new Automobile*[getCap()];
		for (int i = 0; i < getSize(); i++)
		{
			newAutomobiles[i] = automobiles[i];
		}
		newAutomobiles[size++] = new Automobile(a);

		delete[] automobiles;
		automobiles = newAutomobiles;
	}
	else 
	{
		automobiles[getSize()] = new Automobile(a);
		setSize(getSize() + 1);
	}
	

}

bool Dealer::removeAutomobile(int index)
{
	if (index < getSize())
	{
		delete automobiles[index];

		for (int i = index; i < getSize() - 1; i++)
		{
			automobiles[i] = automobiles[i + 1];
		}

		setSize(size - 1);

		return true;
	}
	return false;
}

Automobile & Dealer::getAutomobile(int index)
{
	if (index < getSize())
		return *automobiles[index];
	else cout<<"Index is invalid!";
	
}

void Dealer::setSize(int size)
{
}

int Dealer::getSize() const
{
	return 0;
}

void Dealer::setCap(int cap)
{
}

int Dealer::getCap() const
{
	return 0;
}
