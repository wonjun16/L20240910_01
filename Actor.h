#pragma once
class AActor
{
public:
	AActor()
	{
		X = 10;
		Y = 10;
	}

	virtual ~AActor()
	{

	}

	void Tick(int KeyCode);
	void Render();

	int X;
	int Y;
};

