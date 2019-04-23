#include "Stack.h"
#include <string.h>

int main()
{
	Stack<int> s1;

	s1.push(2);
	s1.push(3);

	s1.print();

	system("pause");
}
