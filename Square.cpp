#include "square.h"
#include "console.h"

Square::Square(COORDINATE BaseIn, int SpeedIn, int colorIn, int LengthIn) : 
	Shape(BaseIn, SpeedIn, colorIn), Length(LengthIn)
{}

bool Square::IsDead()
{
	return Base.x == 25;
}


void Square::Draw(Console& c, char ch, int color)
{
	for (int i = Base.x; i <= Base.x + Length; i++)
	{
		for (int j = Base.y; j <= Base.y + Length; j++)
		{
			c.SetColor(j, i, color);
			c.PrintChar(j, i, ch);
		}
	}
}

