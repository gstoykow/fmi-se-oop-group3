/////////////////////////////////////////////////////////////////////////HHH
#pragma once
#include <iostream>
#include <algorithm>

using namespace std;


class Polynomial
{

private:

	int power;
	double* coefs = nullptr;

	void copy(const Polynomial&);
	void expand(int);

public:

	Polynomial();
	Polynomial(const Polynomial&);
	~Polynomial();

	void setPower(int);
	int getPower()const;

	void setCoef(double coef, int power);

	Polynomial& operator=(const Polynomial&);
	Polynomial& operator+=(const Polynomial&);

	Polynomial operator+(const Polynomial&)const;

	double operator[](int)const;

	friend ostream& operator<<(ostream&,const Polynomial&);

};
/////////////////////////////////////////////////////////////////////////CPP
#include "Polynomial.h"

void Polynomial::copy(const Polynomial &p)
{
	delete[] coefs;
	coefs = new double[p.getPower() + 1];
	for (int i = 0; i < p.getPower() + 1; i++)
	{
		coefs[i] = p.coefs[i];
	}

	setPower(p.getPower());
}

void Polynomial::expand(int power)
{
	double* newCoefs = new double[power + 1];

	for (int i = 0; i < getPower() + 1; i++)
	{
		newCoefs[i] = coefs[i];
	}

	for (int i = getPower() + 1; i < power; i++)
	{
		newCoefs[i] = 0;
	}

	delete[] coefs;
	coefs = newCoefs;
	setPower(power);
}

Polynomial::Polynomial()
{
	setPower(0);
	coefs = new double[getPower() + 1];
	coefs[0] = 0;
}

Polynomial::Polynomial(const Polynomial &p)
{
	copy(p);
}

Polynomial::~Polynomial()
{
	delete[] coefs;
}

void Polynomial::setPower(int power)
{
	this->power = power;
}

int Polynomial::getPower() const
{
	return this->power;
}

void Polynomial::setCoef(double coef, int power)
{
	if (power > getPower())
		expand(power);
	coefs[power] = coef;
}

Polynomial & Polynomial::operator=(const Polynomial &p)
{
	if (this != &p)
	{
		copy(p);
	}

	return *this;
}


Polynomial Polynomial::operator+(const Polynomial &p) const
{
	Polynomial result;
	int greaterPower = max(this->getPower(), p.getPower());
	for (int i = 0; i < greaterPower + 1; i++)
	{
			result.setCoef(((*this)[i] + p[i]),i);
	}

	return result;
}

double Polynomial::operator[](int index) const
{
	if (index > getPower())return 0;
	else return coefs[index];
}

ostream & operator<<(ostream &os, const Polynomial &p)
{
	for (int i = 0; i < p.getPower() + 1; i++)
	{
		if(p[i] != 0)
		os << p[i] << "x^" << i << " ";
	}

	return os;
}
/////////////////////////////////////////////////////////////////////////HHH
#pragma once
#include <iostream>

using namespace std;

class Polynomial
{

private:

	double coef1, coef2;

public:

	Polynomial();
	Polynomial(double,double);
	Polynomial(const Polynomial&);

	void setCoef1(double);
	double getCoef1()const;

	void setCoef2(double);
	double getCoef2()const;

	Polynomial& operator=(const Polynomial&);
	Polynomial& operator+=(const Polynomial&);
	Polynomial& operator-=(const Polynomial&);
	
	Polynomial operator+(const Polynomial&)const;
	Polynomial operator-(const Polynomial&)const;

	Polynomial& operator++();

	bool operator>(const Polynomial&)const;
	bool operator<(const Polynomial&)const;

	friend ostream& operator<<(ostream& os, const Polynomial&);
	friend istream& operator>>(istream& is, Polynomial&);
	
};

/////////////////////////////////////////////////////////////////////////CPP
#include "Polynomial.h"

Polynomial::Polynomial()
{
	setCoef1(1);
	setCoef2(1);
}

Polynomial::Polynomial(double coef1, double coef2)
{
	setCoef1(coef1);
	setCoef2(coef2);
}

Polynomial::Polynomial(const Polynomial& p)
{
	setCoef1(p.getCoef1());
	setCoef2(p.getCoef2());
}

double Polynomial::getCoef1()const
{
	return this->coef1;
}

void Polynomial::setCoef1(double coef1)
{
	this->coef1 = coef1;
}

double Polynomial::getCoef2()const
{
	return this->coef2;
}

void Polynomial::setCoef2(double coef2)
{
	this->coef2 = coef2;
}

Polynomial& Polynomial::operator=(const Polynomial& p)
{
	setCoef1(p.getCoef1());
	setCoef2(p.getCoef2());

	return *this;
}

Polynomial& Polynomial::operator+=(const Polynomial& p)
{
	setCoef1(getCoef1() + p.getCoef1());
	setCoef2(getCoef2() + p.getCoef2());

	return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& p)
{
	setCoef1(getCoef1() - p.getCoef1());
	setCoef2(getCoef2() - p.getCoef2());

	return *this;
}

Polynomial Polynomial::operator+(const Polynomial& p)const
{
	return Polynomial(*this) += p;
}

Polynomial Polynomial::operator-(const Polynomial& p)const
{
	return Polynomial(*this) -= p;
}

Polynomial& Polynomial::operator++()
{
	setCoef1(getCoef1()+1);
	setCoef2(getCoef2()+1);
	
	return *this;
}

bool Polynomial::operator>(const Polynomial& p)const
{
	if (getCoef1() < p.getCoef1() || getCoef2() < p.getCoef2())
		return false;
	else return true;
}

bool Polynomial::operator<(const Polynomial& p)const
{
	if (getCoef1() < p.getCoef1() || getCoef2() < p.getCoef2())
		return true;
	else return false;
}

ostream& operator<<(ostream& os, const Polynomial& p)
{
	os << p.getCoef1()<< "x " << p.getCoef2()<<"x";
	return os;
}
istream& operator>>(istream& is, Polynomial& p)
{
	double coef;

	is >> coef;
	p.setCoef1(coef);

	is >> coef;
	p.setCoef2(coef);

	return is;
}
