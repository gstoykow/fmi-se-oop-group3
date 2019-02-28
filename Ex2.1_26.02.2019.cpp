#include <iostream>

using namespace std;

struct Beer
{
	char* name;
	float price;

	Beer()
	{
		this->name = "Default beer";
		this->price = 2;
	}

	Beer(char* name, float price)
	{
		this->name = name;
		this->price = price;
	}

	Beer(const Beer& b)
	{
		this->name = b.name;
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
		this->username = "Default";
		this->record_count = 0;
		//No need for creating an instance of Beer. It is already created at (*)
	}

	User(char* username, int record_count,const Beer& b)
	{
		this->username = username;
		this->record_count = record_count;
		//using the copy constructor
		this->favourite = Beer(b);
	}

	User(const User& u)
	{
		this->username = u.username;
		this->record_count = u.record_count;
		//using the copy constructor
		this->favourite = Beer(u.favourite);
	}

	~User()
	{
		delete[] username;
	}

};

int main()
{


	cin.get();

}
