#pragma once
#include "Post.h"

class Blog
{

private:

	Post* posts = nullptr;
	int size = 0;

	void incrementSize();
	void decrementSize();

	void resize();

public:

	Blog();
	Blog(const Blog&);
	~Blog();

	const int getSize()const;

	void addPost(const Post&);
	void remPost(int index);

	void printHighRated()const;

	Blog& operator=(const Blog&);
	void operator+=(const Post&);
	Post operator[](int index)const;

};