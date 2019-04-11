#include "Dealer.h"

#include <string.h>
#include <iostream>

using namespace std;

Dealer::Dealer()
{
	setCap(2);
	this->automobiles = new Automobile*[cap];
	setSize(0);
}

Dealer::Dealer(char * name, int cap, Automobile ** automobiles)
{
	setCap(cap);
	this->automobiles = new Automobile*[getCap()];
	setSize(0);
}

Dealer::Dealer(const Dealer & d)
{
	this->automobiles = new Automobile*[d.getCap()];
	for (int i = 0; i < d.getSize(); i++)
	{
		this->automobiles[i] = d.automobiles[i];
	}
    setCap(d.getCap());
	setSize(d.getSize());
}

Dealer::~Dealer()
{
	for (int i = 0; i < getSize(); i++)
	{
		delete automobiles[i];
	}

	delete[] automobiles;
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

        newAutomobiles[size] = new Automobile(a);

        setSize(getSize()+1);

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

        setSize(getSize() - 1);

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
    this->size = size;
}

int Dealer::getSize() const
{
    return this->size;
}

void Dealer::setCap(int cap)
{
    if(cap > 0)
        this->cap = cap;
}



int Dealer::getCap() const
{
    return this->cap;
}
