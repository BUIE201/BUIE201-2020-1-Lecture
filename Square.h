#pragma once

#include "shape.h"

class Console;

class Square : public Shape // declares Shape as a base class of Square
{
	int Length;

public:

	Square(COORDINATE BaseIn, int SpeedIn, int colorIn, int LengthIn);
	bool IsDead();

	// function overriding 
	void Draw(Console& c, char ch, int color);
};
