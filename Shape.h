#pragma once

class Console;

struct COORDINATE
{
	int x;
	int y;

	COORDINATE(int xIn, int yIn) : x(xIn), y(yIn) {}
};

class Shape
{
	int Speed;
	int SpeedCounter;
	int color;

protected:
	COORDINATE Base;

	virtual void Draw(Console& c, char ch, int color) = 0;

public:
	Shape(COORDINATE BaseIn, int SpeedIn, int colorIn);

	void Erase(Console& c);
	void Draw(Console& c);

	virtual bool TimeIsUp(double GameSpeed);
	virtual bool IsDead() = 0;
	void Drop(double GameSpeed, Console& c);
};
