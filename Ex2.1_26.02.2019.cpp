#include <iostream>

using namespace std;

struct Beer
{
	char* name;
	float price;

	Beer()
	{
		this->name = new char[30];
		strcpy_s(this->name, 30, "Default");
		this->price = 2;
	}

	Beer(char* name, float price)
	{
		this->name = new char[30];
		strcpy_s(this->name, 30, name);
		this->price = price;
	}

	Beer(const Beer& b)
	{
		this->name = new char[30];
		strcpy_s(this->name, 30, b.name);
		this->price = b.price;
	}

	~Beer()
	{
		delete[] name;
	}

};

struct User
{
	char* username;
	int record_count;
	//(*)
	Beer favourite;

	User()
	{
		this->username = new char[30];
		strcpy_s(this->username, 30, "Default");
		this->record_count = 0;
		//No need for creating an instance of Beer. It is already created at (*)
	}

	User(char* username, int record_count,const Beer& b)
	{
		this->username = new char[30];
		strcpy_s(this->username, 30, username);
		this->record_count = record_count;
		//using the copy constructor
		//we will learn about the bottom line in future excercises
		//this->favourite = Beer(b);
	}

	User(const User& u)
	{
		this->username = new char[30];
		strcpy_s(this->username, 30, u.username);
		this->record_count = u.record_count;
		//using the copy constructor
		//we will learn about the bottom line in future excercises
		//this->favourite = Beer(u.favourite);
	}

	~User()
	{
		delete[] username;
	}

};

int main()
{
	Beer b1;
	Beer b2(b1);

	User u1("gosho", 5, b1);

	cin.get();

}
