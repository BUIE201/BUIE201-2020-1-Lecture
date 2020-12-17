#include <iostream>

using namespace std;

#include "meat.h"
#include "dish.h"

MEAT::MEAT(int CostIn): DISH(CostIn)
{
}

void MEAT::PrintDISH()
{
	cout << "MEAT = ";
	DISH::PrintDISH();
}

