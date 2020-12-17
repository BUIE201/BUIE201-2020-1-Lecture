#include <iostream>
#include <vector>

using namespace std;

#include "dish.h"
#include "order.h"

void ORDER::AddItem(DISH* pD)
{
	Dishes.push_back(pD);
}

void ORDER::PrintORDER()
{
	int Total = 0;
	for (auto pD : Dishes)
	{
		if (Total > 0)
			cout << ", ";

		pD->PrintDISH();
		Total += pD->GetCost();
	}
	cout << ", TOTAL = " << Total << "TL." << endl;
}
