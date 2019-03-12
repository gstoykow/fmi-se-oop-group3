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
}

char * Dealer::getName() const
{
	return nullptr;
}

void Dealer::addAutomobile(const Automobile & a)
{
	if (size + 1 > cap)
	{
		cap *= 2;
		Automobile** newAutomobiles = new Automobile*[cap];
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
		automobiles[size++] = new Automobile(a);
	}
	

}

bool Dealer::removeAutomobile(int index)
{
	if (index < size)
	{
		delete automobiles[index];

		for (int i = index; i < getSize() - 1; i++)
		{
			automobiles[i] = automobiles[i + 1];
		}

		size--;

		return true;
	}
	return false;
}

Automobile & Dealer::getAutomobile(int index)
{
	if (index < size)
		return *automobiles[index];
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
