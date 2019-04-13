#pragma once
#include <iostream>
#include <string.h>

using namespace std;

class Post
{

private:

	char* subject = nullptr;
	char* body = nullptr;
	int rating;

public:

	Post();
	Post(const Post&);
	~Post();

	void setSubject(const char*);
	void setBody(const char*);
	void setRating(const int);

	const char* getSubject()const;
	const char* getBody()const;
	const int getRating()const;

	Post& operator=(const Post&);
	bool operator>(const Post&)const;
	bool operator<(const Post&)const;

	friend ostream& operator<<(ostream&, const Post&);
	friend istream& operator>>(istream&, Post&);

};