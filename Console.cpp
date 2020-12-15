
#include "console.h"

Console::Console()
{
	hConsoleOutput = CreateConsoleScreenBuffer(GENERIC_WRITE, FILE_SHARE_WRITE, 
		NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsoleOutput);
}

int Console::rgb_b(int r, int g, int b, int intensify)
{
	WORD color = 0;
	if (r)
		color |= BACKGROUND_RED;
	if (g)
		color |= BACKGROUND_GREEN;
	if (b)
		color |= BACKGROUND_BLUE;
	if (intensify)
		color |= FOREGROUND_INTENSITY;
	return color;
}

int Console::rgb_f(int r, int g, int b, int intensify)
{
	WORD color = 0;
	if (r)
		color |= FOREGROUND_RED;
	if (g)
		color |= FOREGROUND_GREEN;
	if (b)
		color |= FOREGROUND_BLUE;
	if (intensify)
		color |= FOREGROUND_INTENSITY;
	return color;
}

void Console::SetColor(int x, int y, int color)
{    
	DWORD NumberOfCharsWritten;
	COORD coordinate;
	coordinate.X = x;
	coordinate.Y = y;
	WriteConsoleOutputAttribute(hConsoleOutput, (WORD*) &color, 1, coordinate, &NumberOfCharsWritten);
}


void Console::PrintChar(int x, int y, char c)
{
	DWORD NumberOfCharsWritten;
	COORD coordinate;
	coordinate.X = x;
	coordinate.Y = y;
	
	WriteConsoleOutputCharacter(hConsoleOutput,  &c, 1, coordinate, &NumberOfCharsWritten);
}

