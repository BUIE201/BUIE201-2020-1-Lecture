#pragma once

#include <conio.h>
#include <windows.h>

class Console
{
	HANDLE hConsoleOutput;

public:
	Console();
	int rgb_b(int r, int g, int b, int intensify);
	int rgb_f(int r, int g, int b, int intensify);
	void SetColor(int x, int y, int color);
	void PrintChar(int x, int y, char c);
};
