#include "Engine.h"
#include "Actor.h"


int main()
{
	Engine MyEngine;

	MyEngine.SpawnActor(new AActor());
	MyEngine.Run();

	return 0;
}