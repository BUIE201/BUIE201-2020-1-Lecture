#include "order.h"
#include "meat.h"
#include "dessert.h"

int main()
{
	ORDER o1;
	auto pM1 = new MEAT(10); // Parameter is the cost of the dish.
	auto pM2 = new MEAT(20); // Parameter is the cost of the dish.
	auto pD1 = new DESSERT(4); // Parameter is the cost of the dish.
	o1.AddItem(pM1);
	o1.AddItem(pM2);
	o1.AddItem(pD1);
	o1.PrintORDER();	// Output should read MEAT = 10TL, MEAT = 20TL, DESSERT = 4TL, TOTAL = 34TL.

	return 1;
}