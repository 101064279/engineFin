#include "pch.h"
#include "TransformComponent.h"
#include<iostream>

void TransformComponent::Start()
{
	std::cout << "Transform Component Initialized" << std::endl;
}

void TransformComponent::Update()
{
	std::cout << "Pos (x: " << position.x << ", y: " << position.y << ")" << std::endl;
}

