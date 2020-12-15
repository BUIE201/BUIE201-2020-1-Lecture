#pragma once

#include "shape.h"

class Console;

class Triangle : public Shape
{
	int Length;

public:

	Triangle(COORDINATE BaseIn, int SpeedIn, int colorIn, int LengthIn);
	bool IsDead();
	void Draw(Console& c, char ch, int color);
};
