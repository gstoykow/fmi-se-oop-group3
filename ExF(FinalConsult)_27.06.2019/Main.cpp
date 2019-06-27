#include "CentralBank.h"

int main()
{
	ConcreteObserver* c1 = new ConcreteObserver("Georgi");
	ConcreteObserver* c2 = new ConcreteObserver("Stoykov");

	CentralBank cb;
	cb.Register(c1);
	cb.Register(c2);

	CentralBank cb2(cb);

	cb2.addCurrency("kinti");

	cb2.setRate("kinti", 5);


	cin.get();
	return 0;
}