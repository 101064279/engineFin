#pragma once
#include "forestStd.h"

class forestFighterEngine : public base<forestFighterEngine>
{
public:
	forestFighterEngine();
	~forestFighterEngine();

	bool Initialize();
	void input();
	void Run();
	bool HasFreeDiskSpace();
	bool ReadCPUSpeed();
	bool CheckMemory();

	sf::Text menuTitle;
	sf::Text menuIntroduced;
	sf::Text Text;
	sf::Font font;

private:
	friend base<forestFighterEngine>;
	forestFighterEngine(const forestFighterEngine &_copy) = delete;
	bool SystemRequirements();
};

