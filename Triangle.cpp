#include "triangle.h"
#include "console.h"

Triangle::Triangle(COORDINATE BaseIn, int SpeedIn, int colorIn, int LengthIn) : 
	Shape(BaseIn, SpeedIn, colorIn), Length(LengthIn)
{}

bool Triangle::IsDead()
{
	return Base.x == 25;
}


void Triangle::Draw(Console& c, char ch, int color)
{
	for (int i = Base.x; i <= Base.x + Length; i++)
	{
		for (int j = Base.y - (i - Base.x); j <= Base.y + (i - Base.x); j++)
		{
			c.SetColor(j, i, color);
			c.PrintChar(j, i, ch);
		}
	}
}
