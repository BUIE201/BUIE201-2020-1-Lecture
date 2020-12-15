#pragma once

#include "shape.h"

class Console;

class Square : public Shape
{
	int Length;

public:

	Square(COORDINATE BaseIn, int SpeedIn, int colorIn, int LengthIn);
	bool IsDead();

	void Draw(Console& c, char ch, int color);
};
