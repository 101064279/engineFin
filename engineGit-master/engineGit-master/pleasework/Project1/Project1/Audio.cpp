#include "Audio.h"
#include "pch.h"
#include <iostream>

sf::Music Audio::music;

Audio::Audio()
{

}
Audio::~Audio()
{

}

void Audio::Initialize()
{
	std::cout << "Audio Started" << "\n";
}

void Audio::PlayMusic(std::string filename)
{
	if (!music.openFromFile(filename))
	{
		printf("Audio not found\n");
		return;
	}
	music.setVolume(50.0f);
	music.play();
	music.setLoop(false);
}

void Audio::StopMusic()
{
	music.stop();
}
void Audio::MuteMusic()
{
	music.setVolume(0.0f);
}

void Audio::UnMuteMusic()
{
	music.setVolume(50.0f);
}
