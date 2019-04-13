#include "Blog.h"

void Blog::incrementSize()
{
	this->size++;
}

void Blog::decrementSize()
{
	this->size--;
}

void Blog::resize()
{
	Post* newPosts = new Post[getSize() + 1];

	for (int i = 0; i < getSize(); i++)
		newPosts[i] = this->posts[i];

	delete[] this->posts;
	this->posts = newPosts;
	incrementSize();
}

Blog::Blog() {}//no need ;/

Blog::Blog(const Blog &b)
{
	*this = b;
}

Blog::~Blog()
{
	delete[] this->posts;
}

const int Blog::getSize() const
{
	return this->size;
}

void Blog::addPost(const Post &p)
{
	resize();
	this->posts[getSize() - 1] = p;
}

void Blog::remPost(int index)
{
	if (index >= getSize())return;

	decrementSize();

	for (int i = index; i < getSize(); i++)
		this->posts[i] = this->posts[i + 1];
}

void Blog::printHighRated() const
{
	for (int i = 0; i < getSize(); i++)
	//	if (posts[i].getRating() > 3)
			cout << posts[i];
}

Blog & Blog::operator=(const Blog &b)
{
	if (this == &b)
		return *this;

	delete[] this->posts;

	for (int i = 0; i < b.getSize(); i++)
		this->addPost(b[i]);
}

void Blog::operator+=(const Post &p)
{
	addPost(p);
}

Post Blog::operator[](int index) const
{
	if (index >= getSize()) return Post();
	else return posts[index];
}
