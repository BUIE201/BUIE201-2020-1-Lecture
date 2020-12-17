#pragma once

#include "dish.h"

class MEAT: public DISH
{
public:
	MEAT(int CostIn);
	void PrintDISH(); // this is an override of the virtual function in DISH
};

