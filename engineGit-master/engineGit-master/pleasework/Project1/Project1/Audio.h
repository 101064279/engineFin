#pragma once
#include <SFML/Audio.hpp>
#include "forestStd.h"
class Audio
{
public:


	Audio();
	~Audio();

	int vol = 1;


	static void Initialize();
	static void PlayMusic(std::string filename);
	static void StopMusic();
	static void UnMuteMusic();
	static void MuteMusic();

	//static void StartSound(std::string filename);

private:

	static sf::Music music;
	static sf::Sound soundEffect;
};

