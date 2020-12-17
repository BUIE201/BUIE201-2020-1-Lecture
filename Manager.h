#pragma once

#include "console.h"
#include <vector>

using namespace std;

class Shape;

class Manager
{
	Console c;
	vector<Shape*> MyShapes;
	double Speed;

	void CreateNewShape(Shape*& pShape);
	void UpdateGameSpeed(char ch);

public:
	Manager();
	~Manager();

	void Run();

};


