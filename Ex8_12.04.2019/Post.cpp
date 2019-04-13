#include "Post.h"

Post::Post()
{
	setSubject("No Subject");
	setBody("");
	setRating(1);
}

Post::Post(const Post &p)
{
	setSubject(p.getSubject());
	setBody(p.getBody());
	setRating(p.getRating());
}

Post::~Post()
{
	delete[] this->subject;
	delete[] this->body;
}

void Post::setSubject(const char * subject)
{
	delete[] this->subject;
	this->subject = new char[strlen(subject) + 1];
	strcpy_s(this->subject, strlen(subject) + 1, subject);
}

void Post::setBody(const char * body)
{
	delete[] this->body;
	this->body = new char[strlen(body) + 1];
	strcpy_s(this->body, strlen(body) + 1, body);
}

void Post::setRating(const int rating)
{
	if (rating > 0 && rating < 6)
		this->rating = rating;
}

const char * Post::getSubject() const
{
	return this->subject;
}

const char * Post::getBody() const
{
	return this->body;
}

const int Post::getRating() const
{
	return this->rating;
}

Post & Post::operator=(const Post &p)
{
	setSubject(p.getSubject());
	setBody(p.getBody());
	setRating(p.getRating());

	return *this;
}

bool Post::operator>(const Post &p)const
{
	if (this->getRating() > p.getRating())
		return true;
	else return false;
}

bool Post::operator<(const Post &p)const
{
	if (this->getRating() > p.getRating())
		return false;
	else return true;
}

ostream & operator<<(ostream &os, const Post &p)
{
	os << "Post Subject: " << p.getSubject() << endl
		<< "Post Body: " << p.getBody() << endl
		<< "Post Rating: " << p.getRating() << endl
		<< "------------------" << endl;

	return os;
}

istream & operator>>(istream &is, Post &p)
{
	char strInput[255];
	int intInput;

	is >> strInput;
	p.setSubject(strInput);

	is >> strInput;
	p.setBody(strInput);

	is >> intInput;
	p.setRating(intInput);

	return is;
}
