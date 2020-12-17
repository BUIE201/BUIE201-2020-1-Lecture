#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include "dish.h"

class DESSERT: public DISH
{
public:
	DESSERT(int CostIn);
	void PrintDISH();
};

