#pragma once
#pragma once
#include <SFML/Graphics.hpp>

class Collider
{
public:
	Collider(sf::RectangleShape& shape);
	~Collider();
	bool move;
	void Move(float dx, float dy) { body.move(dx, dy); move = true; }

	bool CheckCollision(Collider& other, float push);
	bool CheckCollision(Collider other, sf::Vector2f& direction, float push);
	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f; }

private:
	sf::RectangleShape& body;
};

