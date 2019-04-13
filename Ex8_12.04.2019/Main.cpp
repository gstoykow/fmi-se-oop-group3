#include "Blog.h"

int main()
{
	Post p1,p2,p3;

	cin >> p2;

	Blog b;

	b.addPost(p2);
	b.addPost(p1);

	b.remPost(1);

	cin >> p3;

	b.addPost(p3);

	Blog b3;
	b3 = b;

	b3.printHighRated();

	system("pause");
	return 0;
}