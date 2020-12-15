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
	// pure (=0) virtual function
	// sub classes now "must" override and define this function
	// Is a class has at least one pure virtual function
	// than that class is called an "abstract" class.
	// You cannot create a variable of an abstract class.

public:
	Shape(COORDINATE BaseIn, int SpeedIn, int colorIn);

	void Erase(Console& c);
	void Draw(Console& c);

	virtual bool TimeIsUp(double GameSpeed);
	virtual bool IsDead() = 0;
	void Drop(double GameSpeed, Console& c);
};
