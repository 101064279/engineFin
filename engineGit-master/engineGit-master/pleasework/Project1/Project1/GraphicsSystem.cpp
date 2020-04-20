#include "pch.h"
#include "GraphicsSystem.h"
#include "windows.h"
#include"Initialise.h"
#include "forestStd.h"

GraphicsSystem::GraphicsSystem()
{
}

GraphicsSystem::~GraphicsSystem()
{
}

void GraphicsSystem::CreateWin()
{
	Engine::Instance()->InitalizeWindow();
}
void GraphicsSystem::draw(sf::RenderWindow win)
{
	win.display();
}
