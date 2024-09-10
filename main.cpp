#include "Engine.h"
#include <fstream>
#include <iostream>

int main()
{
	std::fstream MapStream;
	MapStream.open("Level01.map");
	if (MapStream.fail())
	{
		std::cerr << "Error!" << std::endl;
		return -1;
	}

	GEngine->LoadLevel(MapStream);

	GEngine->Run();

	//GEngine->SaveLevel(MapStream);
	return 0;
}