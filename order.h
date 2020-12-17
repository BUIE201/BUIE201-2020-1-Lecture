#pragma once

#include <vector>
#include <memory>

using namespace std;

#include "dish.h"

class ORDER
{
	vector<DISH*> Dishes;

public:
	void AddItem(DISH* pD);
	void PrintORDER();
};
