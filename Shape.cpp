
#include <math.h>
#include "shape.h"
#include "console.h"

Shape::Shape(COORDINATE BaseIn, int SpeedIn, int colorIn) : Base(BaseIn), Speed(SpeedIn), color(colorIn)
{
	SpeedCounter=0;
}

void Shape::Erase(Console& c)
{
	Draw(c, ' ', c.rgb_b(0,0,0,0) | c.rgb_f(0,0,0,0));
}
void Shape::Draw(Console& c)
{
	Draw(c, '.', color);
}

bool Shape::TimeIsUp(double GameSpeed)
{
	if (ceil((double) Speed / GameSpeed) <= SpeedCounter)
	{
		SpeedCounter = 0;
		return true;
	}
	SpeedCounter++;
	return false;
}

void Shape::Drop(double GameSpeed, Console& c)
{
	if (!TimeIsUp(GameSpeed))
		return;

	Erase(c);
	Base.x++;
	Draw(c);
}
