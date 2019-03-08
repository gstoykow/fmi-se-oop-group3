#include "Automobile.h"

using namespace std;

int maxPriceAutomobile(Automobile* automobiles, int n)
{
	float max_price = 0;
	int maxp_index = -1;

	for (int i = 0; i < n; i++)
	{
		if (automobiles[i].getPrice() > max_price)
		{
			maxp_index = i;
			max_price = automobiles[i].getPrice();
		}
	}

	return maxp_index;
}

int main()
{
	Automobile a1;
	Automobile a2("Ofell", 1, 200, 40000);
	Automobile a3(a2);

	a1.print();
	a2.print();
	a3.print();

	a2.comparePower(a1);
	
	int N;
	do
	{
		cin >> N;
	} while (N < 1);

	Automobile* automobiles = new Automobile[N];

	for (int i = 0; i < N; i++)
	{
		char* brand = new char[100];
		cin >> brand;

		unsigned int type;
		cin >> type;

		unsigned int power;
		cin >> power;

		float price;
		cin >> price;

		Automobile new_auto(brand, type, power, price);
		automobiles[i] = new_auto;
		delete[] brand;
	}

	automobiles[maxPriceAutomobile(automobiles, N)].print();
	
	delete[] automobiles;

	cin.get();
	return 0;
}
