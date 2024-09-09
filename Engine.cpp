#include "Engine.h"

#include <conio.h>
#include <stdio.h>
#include <Windows.h>

#include "Actor.h"

void Engine::Input()
{
	KeyCode = _getch();
}

void Engine::Render()
{
	system("cls");

	//AllActorofClass->Render();
	//for (int i = 0; i < Actors.size(); ++i)
	//{
	//	Actors[i]->Render();
	//}

	for (const auto& Selected : Actors)
	{
		Selected->Render();
	}

}

void Engine::Run()
{
	while (bIsRunning)
	{
		Input();

		Tick();

		Render();
	}
}

void Engine::SpawnActor(AActor* SpawnedActor)
{
	Actors.push_back(SpawnedActor);
}

void Engine::Tick()
{
	//AllActorofClass->Tick();

	for (int i = 0; i < Actors.size(); ++i)
	{
		Actors[i]->Tick(KeyCode);
	}
}