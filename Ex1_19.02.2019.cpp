#include <iostream>

using namespace std;

struct Beer
{
	char* name;
	float price;
};
// (1),(2),(3) -> used for creating instances
// (4) -> used for clearing dynamic memory
struct User
{
	char* username;
	int record_count;
	//Beer favourite;

	// (1) Default constructor
	User()
	{
		this->username = new char[30];
		strcpy_s(this->username, 30, "Default");
		this->record_count = 0;
	}

	// (2) Constructor with parameters
	User(char* username, int record_count)
	{
		this->username = new char[30];
		strcpy_s(this->username, 30, username);
		this->record_count = record_count;
	}

	// (3) constant reference to an existing user
	User(const User& u)
	{
		this->username = new char[30];
		strcpy_s(this->username, 30, u.username);
		this->record_count = u.record_count;
	}

	// (4) Destructor
	~User()
	{
		delete[] username;
	}

};

int main()
{
	//examples for using the 3 types of constructors for creating instances 

	User u1; // (1)
	User u2("georgi", 20); // (2)
	User u3(u2); // (3)

	cin.get();
}
//when the main function is complete, (4) is called by the compiler
