#include "TV.h"

using namespace std;

TV::TV()
{
	setName("");
	setWidth(0);
	setHeight(0);
}

TV::TV(const TV &t)
{
	*this = t;
}

TV::TV(const char * Name, const int Width, const int Height)
{

	setName(Name);
	setWidth(Width);
	setHeight(Height);

}

TV & TV::operator=(const TV &t)
{
	setName(t.getName());
	setWidth(t.getWidth());
	setHeight(t.getHeight());

	return *this;
}

TV::~TV()
{
	delete[] Name;
}

void TV::setName(const char * Name)
{
	delete[] this->Name;
	this->Name = new char[strlen(Name) + 1];
	strcpy_s(this->Name, strlen(Name) + 1, Name);
}

void TV::setWidth(const int Width)
{
	this->Width = Width;
}

void TV::setHeight(const int Height)
{
	this->Height = Height;
}

const char * TV::getName() const
{
	return this->Name;
}

const int TV::getWidth() const
{
	return this->Width;
}

const int TV::getHeight() const
{
	return this->Height;
}

void TV::ConnectTo(TV t) const
{
	cout << t.getName() << endl;
}

void TV::Print() const
{
	cout << getName() << endl
		<< getWidth() << endl
		<< getHeight() << endl;
}
