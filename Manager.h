#pragma once

#include "console.h"
class Shape;

class Manager
{
	Console c;
	Shape** MyShapes;
	double Speed;

	void CreateNewShape(int i);
	void UpdateGameSpeed(char ch);

public:
	Manager();
	~Manager();

	void Run();

};


