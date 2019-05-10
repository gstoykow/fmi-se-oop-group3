#include "Settings.h"

int main()
{	
	Settings<string> s1;
	s1.set("key1", "value1");
	s1.set("key2", "value2");

	string a;

	Settings<string> s2(s1);

	s2.get("key2", a);

	cout << a <<endl;

	s2.print();

	//s1.print();

	cin.get();
	return 0;
}