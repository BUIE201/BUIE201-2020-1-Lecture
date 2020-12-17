#include <iostream>

using namespace std;

#include "dish.h"

DISH::DISH(int CostIn) : Cost(CostIn)
{
}

void DISH::PrintDISH()
{
	cout << Cost << "TL";
}

int DISH::GetCost()  
{ 
	return Cost; 
}

