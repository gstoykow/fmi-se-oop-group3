#pragma once
#include <string>
#include <iostream>

class TV
{

private:

	char* Name = nullptr;
	int Width = 0;
	int Height = 0;

public:

	TV();
	TV(const TV&);
	TV(const char*, const int, const int);
	TV& operator=(const TV&);
	~TV();

	void setName(const char*);
	void setWidth(const int);
	void setHeight(const int);

	const char* getName()const;
	const int getWidth()const;
	const int getHeight()const;

	void ConnectTo(TV)const;

	void Print()const;

};