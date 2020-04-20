#pragma once
#include "Update.h"
#include "forestStd.h"
class Update
{
public:
	sf::Clock clock;
	sf::Time dt = clock.restart();
	Update(float dtAsSec);
	~Update();

};

