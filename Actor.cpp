#include "Actor.h"
#include <Windows.h>
#include <stdio.h>

void AActor::Tick(int KeyCode)
{
	if (KeyCode == 'w')
	{
		Y--;
	}
	if (KeyCode == 'a')
	{
		X--;
	}
	if (KeyCode == 's')
	{
		Y++;
	}
	if (KeyCode == 'd')
	{
		X++;
	}

}

void AActor::Render()
{
	COORD Cur;
	Cur.X = X;
	Cur.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
	printf("*");
}
