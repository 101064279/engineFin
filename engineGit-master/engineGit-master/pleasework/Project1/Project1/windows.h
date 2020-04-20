#pragma once
#include "base.h"
#include <SFML/Window.hpp>
#include "forestStd.h"



class Engine : public base <Engine>
{
private:
	sf::Window* window;
	sf::Sprite Background;
	sf::Texture BackgroundTex;
	sf::Clock clock;
	float dtAsSeconds;
	sf::Vector2f resolution;

private:
	friend base;

public:
	Engine();

	sf::Window* GetWindow() const;
	void InitalizeWindow();
	void NotifyCloseRequest();
	void SplashScreen();
	void mainWindow();
	void endWindow();
	sf::RenderWindow Window;
	sf::Music music;
};

