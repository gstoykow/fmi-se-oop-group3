#pragma once
#include <iostream>
#include <string>

using namespace std;

template<class T>
class Pair 
{
	
private:

	char* key = nullptr;
	T value;

public:

	Pair() 
	{
		setKey("");
	}

	Pair(const char* key,  T value)
	{
		setKey(key);
		setValue(value);
	}

	Pair& operator=(const Pair& p)
	{
		setKey(p.getKey());
		setValue(p.getValue());

		return *this;
	}

	Pair(const Pair& p)
	{
		*this = p;
	}

	~Pair()
	{
		delete[] this->key;
	}

	const char* getKey()const
	{
		return this->key;
	}

	T Pair<T>::getValue()const
	{
		return this->value;
	}

	void setKey(const char* key)
	{
		delete[] this->key;
		this->key = new char[strlen(key) + 1];
		strcpy_s(this->key, strlen(key) + 1, key);
	}

	void setValue(T value)
	{
		this->value = value;
	}

	friend ostream& operator<<(ostream& os, const Pair<T>& p);

};

template<class T>
ostream & operator<<(ostream & os, const Pair<T>& p)
{
	os << p.getKey() << " " << p.getValue() << endl;

	return os;
}
