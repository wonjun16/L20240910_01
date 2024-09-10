#pragma once
#include <vector>
#include <fstream>

class AActor;

class Engine
{
private:
	Engine()
	{
		KeyCode = 0;
		bIsRunning = true;
	}

public:
	static Engine* GetInstance()
	{
		if (!Instance)
		{
			Instance = new Engine();
		}

		return Instance;
	}




	virtual ~Engine()
	{

	}

protected:
	void Input();
	void Tick();
	void Render();


	std::vector<AActor*> Actors;
	int KeyCode;
	bool bIsRunning;

	static Engine* Instance;

public:
	void Run();
	void SpawnActor(class AActor* SpawnedActor);
	void LoadLevel(std::fstream &MapStream);
	static bool SortActors(AActor* a, AActor* b);
	//void SaveLevel(std::fstream& MapStream);
};

#define GEngine			Engine::GetInstance()

