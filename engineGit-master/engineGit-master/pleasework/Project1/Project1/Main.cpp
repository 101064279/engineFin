//#include <SFML\Graphics.hpp>
//#include <SFML\Window.hpp>
#include <iostream>
#include "Initialise.h"
#include "Audio.h"



using namespace std;

int main()
{
	forestFighterEngine::Instance()->Initialize();
	forestFighterEngine::Instance()->Run();



	return 0;
}


