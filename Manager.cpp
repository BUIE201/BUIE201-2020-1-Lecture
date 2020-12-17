#define MaxObj 9
#define MaxLength 5
#define MaxY 65
#define MaxSpeed 20
#define SpeedControl 2500
#define SpeedChange 0.1
#define Slowest 0.1
#define Fastest 20

#include <iostream>
#include "manager.h"
#include "shape.h"
#include "square.h"
#include "triangle.h"


Manager::Manager()
{
	Speed = 1.0;

	MyShapes.resize(MaxObj, nullptr);
	for (auto& pShape : MyShapes)
		CreateNewShape(pShape);
}

Manager::~Manager()
{
	for(auto pShape : MyShapes)	
		delete pShape;
}

void Manager::CreateNewShape(Shape*& pShape)
{
	if (pShape)
		delete pShape;

	if (rand() % 2 == 0)
		pShape = new Square(COORDINATE(0, (rand()%MaxY)), ((rand()%MaxSpeed)+1), 
			c.rgb_b(rand()%2,rand()%2,rand()%2,rand()%2) | c.rgb_f(rand()%2,rand()%2,rand()%2,rand()%2), 
			((rand()%MaxLength)+1));
	else
		pShape = new Triangle(COORDINATE(0, (rand()%MaxY)), ((rand()%MaxSpeed)+1), 
			c.rgb_b(rand()%2,rand()%2,rand()%2,rand()%2) | c.rgb_f(rand()%2,rand()%2,rand()%2,rand()%2), 
			((rand()%MaxLength)+1));
}

void Manager::Run()
{
	while(true)
	{
		Sleep(1);

		if (_kbhit())
		{
			char ch = _getch();
			UpdateGameSpeed(ch);
		}
		
		for (auto& pShape : MyShapes)
		{
			pShape->Drop(Speed, c);
			if (pShape->IsDead())
				CreateNewShape(pShape);
		}
	}
}

void Manager::UpdateGameSpeed(char ch)
{
	if (ch == '1' && Speed > Slowest)
		Speed -= SpeedChange; 
	
	if (ch == '2' && Speed < Fastest)
		Speed += SpeedChange;  
}

