#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include "dessert.h"

DESSERT::DESSERT(int CostIn): DISH(CostIn)
{}

void DESSERT::PrintDISH()
{
	cout << "DESSERT = ";
	DISH::PrintDISH();
}

