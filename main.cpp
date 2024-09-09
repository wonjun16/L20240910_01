#include "Engine.h"
#include "Actor.h"
#include "Player.h"

int main()
{
	Engine MyEngine;

	APlayer* MyPlayer = new APlayer(); 
	MyPlayer->SetX(5);
	MyPlayer->SetY(8);
	MyPlayer->SetStaticMesh('P');

	MyEngine.SpawnActor(MyPlayer);
	MyEngine.Run();

	return 0;
}