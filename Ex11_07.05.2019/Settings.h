#pragma once
#include "Pair.h"

template<class T>
class Settings
{

private:

	Pair<T>* pairs = nullptr;
	int size = 0;

	const int getSize()const
	{
		return this->size;
	}

	void incrementSize()
	{
		this->size++;
	}

	void decrementSize()
	{
		this->size--;
	}

	void resize()
	{
		Pair<T>* newPairs = new Pair<T>[getSize() + 1];

		for (int i = 0; i < getSize(); i++)
			newPairs[i] = this->pairs[i];

		delete[] this->pairs;
		this->pairs = newPairs;
		incrementSize();
	}

public:

	Settings()
	{
		this->pairs = nullptr;
		size = 0;
	}

	Settings<T>& operator=(const Settings<T>& s)
	{
		if (this == &s)
			return *this;

		delete[] pairs;

		for (int i = 0; i < s.getSize(); i++)
			set(s.pairs[i].getKey(), s.pairs[i].getValue());

		return *this;
	}

	Settings(const Settings<T>& s)
	{	
		*this = s;
	}

	~Settings()
	{
		delete[] pairs;
	}

	void set(const char* key, const T value)
	{
		for (int i = 0; i < getSize(); i++)
		{
			if (strcmp(this->pairs[i].getKey(), key) == 0)
			{
				pairs[i].setValue(value);
				return;
			}
		}

		resize();
		pairs[getSize() - 1] = Pair<T>(key, value);
	}

	bool get(const char* key , T& out)
	{
		for (int i = 0; i < getSize(); i++)
		{
			if (strcmp(this->pairs[i].getKey(), key) == 0)
			{
				out = pairs[i].getValue();
				return true;
			}
		}
		return false;
	}

	void print()const
	{
		for (int i = 0; i < getSize(); i++)
		{
			cout << pairs[i];
		}
	}

};