#include "pch.h"
#include "Windows.h"
#include <SFML/Window.hpp>
#include "forestStd.h"
#include "GameObject.h"
#include "Initialise.h"
#include "Input.h"
#include "TransformComponent.h"
#include "sceneManager.h"
#include "PhysicsComponent.h"
#include "Bullet.h"
#include <iostream>
#include <stdlib.h>

Engine::Engine()
{

}
float sec;
float x = 0;
forestFighterEngine forest;

void Engine::InitalizeWindow()
{
	resolution.x = sf::VideoMode::getDesktopMode().width;
	resolution.y = sf::VideoMode::getDesktopMode().height;

	//font
	forest.font.loadFromFile("blackjack.otf");
	forest.Text.setFont(forest.font);
	forest.Text.setFillColor(sf::Color::White);
	forest.Text.setCharacterSize(30);
	forest.Text.setPosition(20, 0);

	SplashScreen();
	sf::Texture s = sf::Texture();
}

sf::Window* Engine::GetWindow() const
{

	return window;
}
void Engine::NotifyCloseRequest()
{

	window->close();
}

void Engine::SplashScreen()
{
	SCENE scene = SPLASH;
	int GAME_STATE = SPLASH;
	Window.create(sf::VideoMode(resolution.x, resolution.y), "Splash Screen", sf::Style::Default);

	//splash screen

	GameObject *actor = new GameObject();
	actor->setImage("spashscreen.jpg");
	actor->setobjectPosition({ 1000,500 });
	actor->Scale({ 2.5f,2.3f });




	while (Window.isOpen())
	{
		sf::Event event;
		while (Window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				Window.close();
		}
		Input input;
		input.inputCheck();
		if (GAME_STATE == SPLASH)
		{
			Update::Update(dtAsSeconds);
			sec++;

			//draw actor
			Window.draw(actor->sprite);

			if (sec == 4000.0f)
			{
				GAME_STATE = MENU;
			}
		}

		if (GAME_STATE == MENU)
		{
	
			Window.clear();
			forest.menuTitle.setFont(forest.font);
			forest.menuTitle.setFillColor(sf::Color::White);
			forest.menuTitle.setCharacterSize(30);
			forest.menuTitle.setPosition(980, 400);
			forest.menuTitle.setString("Forest Engine Menu");
			Window.draw(forest.menuTitle);

			forest.menuIntroduced.setFont(forest.font);
			forest.menuIntroduced.setFillColor(sf::Color::White);
			forest.menuIntroduced.setCharacterSize(30);
			forest.menuIntroduced.setPosition(resolution.x / 2, resolution.y / 2);
			forest.menuIntroduced.setString("Press space to start game");
			Window.draw(forest.menuIntroduced);


			if (input.isSpacePressed)
			{
				GAME_STATE = GAME;
			}
		}
		if (GAME_STATE == GAME)
		{
			mainWindow();
		}
		Window.display();

	}

}

void Engine::mainWindow()
{
	SCENE scene = GAME;
	int GAME_STATE = GAME;

	//start secondary sound 
	sf::SoundBuffer buffer;
	buffer.loadFromFile("ChillingMusic.wav");
	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.play();
	sound.setVolume(20.0f);

	Window.create(sf::VideoMode(resolution.x, resolution.y), "Main", sf::Style::Default);
	Window.setFramerateLimit(120);
	WPARAM wParam = NULL;

	sf::Clock timer;
	sf::Time dt = timer.restart();

	float tileSize = 50;
	float xStart = 485;
	float yStart = 65;

	//black boarders

	GameObject *blackWalls = new GameObject[4];

	//top 
	GameObject *blackwallOne = new GameObject();
	blackWalls[0] = *blackwallOne;
	blackWalls[0].setImage("BlackBox.png");
	blackWalls[0].setBodySize({ 1920,40 });
	blackWalls[0].setBodyOrigin({ 960,20 });
	blackWalls[0].setobjectPosition({ 960,1 });
	//bottom
	GameObject *blackwallTwo = new GameObject();
	blackWalls[1] = *blackwallTwo;
	blackWalls[1].setImage("BlackBox.png");
	blackWalls[1].setBodySize({ 1920,40 });
	blackWalls[1].setBodyOrigin({ 960,20 });
	blackWalls[1].setobjectPosition({ 960, 1020 });
	
	GameObject *blackwallThree = new GameObject();
	blackWalls[2] = *blackwallThree;
	blackWalls[2].setImage("BlackBox.png");
	blackWalls[2].setBodySize({ 460,1080 });
	blackWalls[2].setBodyOrigin({ 230,540 });
	blackWalls[2].setobjectPosition({ 1,540 });
	//right
	GameObject *blackwallFour = new GameObject();
	blackWalls[3] = *blackwallFour;
	blackWalls[3].setImage("BlackBox.png");
	blackWalls[3].setBodySize({ 460,1080 });
	blackWalls[3].setBodyOrigin({ 230,540 });
	blackWalls[3].setobjectPosition({ 2050,540 });

	//list of actor not that arent player
	GameObject *object = new GameObject[500];
	int numOfEnemies = 0;

	bool grid[10][10];
	for (int row = 0; row < 10; row++) {
		for (int column = 0; column < 1; column++) {
			grid[row][column] = false;
		}
	}

	GameObject *soldier = new GameObject[500];

	for (float x = 2; x < 4; x++)
	{
		for (float y = 4; y < 5; y++)
		{
			GameObject *brick = new GameObject();
			soldier[numOfEnemies] = *brick;
			soldier[numOfEnemies].setobjectPosition({ xStart + (tileSize*x), yStart + (tileSize*y) });
			soldier[numOfEnemies].setImage("Army.jpg");
			numOfEnemies++;
		}
	}

//2 soldier
	for (float x = 4; x < 6; x++)
	{
		for (float y = 4; y <5; y++)
		{
			GameObject *brick = new GameObject();
			soldier[numOfEnemies] = *brick;
			soldier[numOfEnemies].setobjectPosition({ xStart + (tileSize*x), yStart + (tileSize*y) });
			soldier[numOfEnemies].setImage("Army.jpg");
			numOfEnemies++;
		}
	}
	for (float x = 6; x < 8; x++)
	{
		for (float y = 6; y < 8; y++)
		{
			GameObject *brick = new GameObject();
			soldier[numOfEnemies] = *brick;
			soldier[numOfEnemies].setobjectPosition({ xStart + (tileSize*x), yStart + (tileSize*y) });
			soldier[numOfEnemies].setImage("Army.jpg");
			numOfEnemies++;
		}
	}

	//player

	GameObject *player = new GameObject();
	player->setImage("tank.jpg");
	player->Scale({ 1.5f,1.5f });
	player->setobjectPosition({ xStart + (tileSize * 10), yStart + (tileSize * 10) });

	PhysicsComponent physicsEngine;

	Bullet *PBullets = new Bullet[500];
	int numOfPBullets = 0;
	int bulletTimer = 0;
	bool loop = true;


	while (Window.isOpen())
	{
		sf::Event event;
		while (Window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				Window.close();
		}
		dtAsSeconds = dt.asSeconds();
		forest.Text.setString("Timer: " + std::to_string(timer.getElapsedTime().asSeconds()));
		TransformComponent actorTransform;

		Window.clear(sf::Color::Black);

		if (bulletTimer > 0)
			bulletTimer--;

		sf::Vector2f direction;

		Input input;
		input.ProcessInput(wParam);
		input.inputCheck();

		if (input.isDownPressed) {

			player->moveObject({ 0 ,player->velocity.y * 1.5f });
			player->setrotation(180);
		}

		else if (input.isUpPressed) {

			player->moveObject({ 0 ,-player->velocity.y * 1.5f });
			player->setrotation(0);
		}

		else if (input.isLeftPressed) {

			player->moveObject({ -player->velocity.x * 1.5f  ,0 });
			player->setrotation(270);
		}

		else if (input.isRightPressed) {

			player->moveObject({ player->velocity.x * 1.5f  ,0 });
			player->setrotation(90);
		}

		if (input.isSPressed) {

			Audio::PlayMusic("gunshot.wav"); // audio 

			if (bulletTimer <= 0)
			{
				Bullet *bullet = new Bullet();

				if (player->getRotation() == 0)
				{
					bullet = new Bullet(1, 8.0f, { player->getPosition().x,player->getPosition().y - 2 });
					PBullets[numOfPBullets] = *bullet;
					numOfPBullets++;
				}
				else if (player->getRotation() == 90)
				{
					bullet = new Bullet(2, 8.0f, { player->getPosition().x + 2,player->getPosition().y });
					PBullets[numOfPBullets] = *bullet;
					numOfPBullets++;
				}
				else if (player->getRotation() == 180)
				{
					bullet = new Bullet(3, 8.0f, { player->getPosition().x,player->getPosition().y + 2 });
					PBullets[numOfPBullets] = *bullet;
					numOfPBullets++;
				}
				else if (player->getRotation() == 270)
				{
					bullet = new Bullet(4, 8.0f, { player->getPosition().x - 2,player->getPosition().y });
					PBullets[numOfPBullets] = *bullet;
					numOfPBullets++;
				}
				bulletTimer = 35;
			}
		}

		else if (input.isEscapePressed) 
		{
			exit(EXIT_SUCCESS);
		
		}

		player->draw(Window);

		for (int i = 0; i < numOfEnemies; i++)
		{
			 if (soldier[i].stage == 1)
				soldier[i].setImage("Army2.jpg");
			soldier[i].draw(Window);
			player->getcollider().CheckCollision(soldier[i].getcollider(), direction, 1.0f);
			player->setobjectPosition(player->body.getPosition());

		}

		for (int i = 0; i < 4; i++)
		{
			blackWalls[i].draw(Window);
			player->getcollider().CheckCollision(blackWalls[i].getcollider(), direction, 1.0f);
			player->setobjectPosition(player->body.getPosition());
		}

		for (int i = 0; i < numOfPBullets; i++)
		{
			PBullets[i].updateBullet();
			PBullets[i].setImage("Ball.png");
			PBullets[i].draw(Window);
			loop = true;

			for (int other = 0; other < 4 && loop == true; other++)
			{
				if (PBullets[i].getcollider().CheckCollision(blackWalls[other].getcollider(), direction, 1.0f))

				{
					for (int a = i; a < numOfPBullets; a++)
					{
						PBullets[a] = PBullets[a + 1];
					}
					numOfPBullets--;
					loop = false;
				}
			}
			for (int other = 0; other < numOfEnemies && loop == true; other++)
			{
				if (PBullets[i].getcollider().CheckCollision(soldier[other].getcollider(), direction, 1.0f))

				{
					for (int a = i; a < numOfPBullets; a++)
					{
						PBullets[a] = PBullets[a + 1];
					}
					numOfPBullets--;
					loop = false;

					//Change enemy picture 
					if (soldier[other].stage == 1)
					{
						numOfEnemies--;
						for (int a = other; a < numOfEnemies; a++)
						{
							soldier[a] = soldier[a + 1];
						}
					}
					else
					{
						soldier[other].stage++;
					}
					if (numOfEnemies == 0)
					{
						exit(EXIT_SUCCESS);
					}
				}
			}
		}

			Window.draw(forest.Text);
			Window.display();
	}
}

