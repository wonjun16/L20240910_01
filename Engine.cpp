#include "Engine.h"

#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#include <algorithm>

#include "Actor.h"
#include "Player.h"
#include "Monster.h"
#include "Wall.h"
#include "Floor.h"
#include "Goal.h"

Engine* Engine::Instance = nullptr;
enum class EDepth;

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

bool Engine::SortActors(AActor* a, AActor* b)
{
	return a->GetDepth() < b->GetDepth();
}

//void Engine::SaveLevel(std::fstream& MapStream)
//{
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j < 10; j++)
//		{
//			MapStream << Map[j][i];
//		}
//		MapStream << std::endl;
//	}
//}

void Engine::SpawnActor(AActor* SpawnedActor)
{
	Actors.push_back(SpawnedActor);
}

void Engine::LoadLevel(std::fstream &MapStream)
{
	int index = 0;
	char line[11] = { 0, };
	while (MapStream.getline(line, 11)) {
		for (int i = 0; i < 10; i++)
		{
			if (line[i] == '*')
			{
				AWall* Wall = new AWall();
				Wall->SetX(i);
				Wall->SetY(index);
				Wall->SetStaticMesh(line[i]);
				GEngine->SpawnActor(Wall);
			}
			else if (line[i] == 'P')
			{
				APlayer* MyPlayer = new APlayer();
				MyPlayer->SetX(i);
				MyPlayer->SetY(index);
				MyPlayer->SetStaticMesh(line[i]);
				GEngine->SpawnActor(MyPlayer);
			}
			else if (line[i] == 'M')
			{
				AMonster* Monster = new AMonster();
				Monster->SetX(i);
				Monster->SetY(index);
				Monster->SetStaticMesh(line[i]);
				GEngine->SpawnActor(Monster);
			}
			else if (line[i] == ' ')
			{
				AFloor* Floor = new AFloor();
				Floor->SetX(i);
				Floor->SetY(index);
				Floor->SetStaticMesh(line[i]);
				GEngine->SpawnActor(Floor);
			}
			else if (line[i] == 'G')
			{
				AGoal* Goal = new AGoal();
				Goal->SetX(i);
				Goal->SetY(index);
				Goal->SetStaticMesh(line[i]);
				GEngine->SpawnActor(Goal);
			}
		}
		index++;
	}

	/*for (int Y = 0; Y < 10; ++Y)
	{
		for (int X = 0; X < 10; ++X)
		{
			if (Map[Y][X] == '*')
			{
				AWall* Wall = new AWall();
				Wall->SetX(X);
				Wall->SetY(Y);
				Wall->SetStaticMesh(Map[Y][X]);
				GEngine->SpawnActor(Wall);
			}
			else if (Map[Y][X] == 'P')
			{
				APlayer* MyPlayer = new APlayer();
				MyPlayer->SetX(X);
				MyPlayer->SetY(Y);
				MyPlayer->SetStaticMesh(Map[Y][X]);
				GEngine->SpawnActor(MyPlayer);
			}
			else if (Map[Y][X] == 'M')
			{
				AMonster* Monster = new AMonster();
				Monster->SetX(X);
				Monster->SetY(Y);
				Monster->SetStaticMesh(Map[Y][X]);
				GEngine->SpawnActor(Monster);
			}
			else if (Map[Y][X] == ' ')
			{
				AFloor* Floor = new AFloor();
				Floor->SetX(X);
				Floor->SetY(Y);
				Floor->SetStaticMesh(Map[Y][X]);
				GEngine->SpawnActor(Floor);
			}
			else if (Map[Y][X] == 'G')
			{
				AGoal* Goal = new AGoal();
				Goal->SetX(X);
				Goal->SetY(Y);
				Goal->SetStaticMesh(Map[Y][X]);
				GEngine->SpawnActor(Goal);
			}
		}
	}*/

	sort(Actors.begin(), Actors.end(), SortActors);

	for (const auto& i : Actors)
	{
		EDepth k = i->GetDepth();
	}
}

void Engine::Tick()
{
	//AllActorofClass->Tick();

	if (KeyCode == 27)
	{
		bIsRunning = false;
	}

	for (int i = 0; i < Actors.size(); ++i)
	{
		Actors[i]->Tick(KeyCode);
	}
}