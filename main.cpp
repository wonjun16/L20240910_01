#include "Engine.h"
#include "Actor.h"
#include "Player.h"
#include "Monster.h"

int main()
{
	APlayer* MyPlayer = new APlayer(); 
	MyPlayer->SetX(5);
	MyPlayer->SetY(8);
	MyPlayer->SetStaticMesh('P');
	GEngine->SpawnActor(MyPlayer);

	AMonster* Monster = new AMonster();
	Monster->SetX(10);
	Monster->SetY(10);
	Monster->SetStaticMesh('M');
	GEngine->SpawnActor(Monster);

	GEngine->Run();

	return 0;
}