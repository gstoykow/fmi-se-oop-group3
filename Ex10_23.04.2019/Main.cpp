#include "Electromobile.h"
#include <iostream>

using namespace std;

int main()
{

	Electromobile* e1 = new Electromobile();
	delete e1;

	Dog d;
	Cat c;

	d.makeNoise();
	c.makeNoise();

	cin.get();
	return 0;
}