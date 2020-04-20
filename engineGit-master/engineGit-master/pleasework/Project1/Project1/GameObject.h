#pragma once
#include <vector>
#include <list>
#include <map>
#include <SFML/Graphics.hpp>
#include "Collider.h"

class GameObject : public sf::Transformable
{
public:
	GameObject();
	~GameObject(void);

	void setParent(GameObject& p) { parent = &p; };
	void AddChild(GameObject* s);

	virtual void Update(float msec);

	void Start();
	void setImage(std::string image);
	void setobjectPosition(sf::Vector2f newpos);
	void draw(sf::RenderWindow &window);

	sf::Sprite sprite;
	sf::Texture actorTexture;


	float centerX = sprite.getGlobalBounds().width / 2;
	float centerY = sprite.getGlobalBounds().height / 2;
	int stage;

	sf::Vector2f position;
	sf::Vector2f ChildOffsetFromParent;
	float distanceFromParent;
	sf::Vector2f rotationOffsetFromParent;
	float initialAngleToParent;
	sf::Vector2f velocity = sf::Vector2f(1, 1);
	float bounciness = 1;
	float mass = 1;
	sf::Transformable transform;
	sf::Clock clock;
	sf::Time dt = clock.restart();


	void setrotation(float x);

	void moveObject(sf::Vector2f m);
	void rotateObject(float x);
	void scaleObject(sf::Vector2f m);
	void Scale(sf::Vector2f m);
	void setBodySize(sf::Vector2f m);
	void setBodyOrigin(sf::Vector2f m);
	void UpdateTransform(float dtAsSec);

	Collider getcollider() { return Collider(body); };

	void oncollision(sf::Vector2f direction);
	sf::Transform transforms;

	sf::RectangleShape body;

private:
	std::map<int, GameObject*> m_Objects;
	static int nextObjectID;



protected:
	GameObject* parent;
	sf::Transformable worldTransform;

	std::vector<GameObject*>children;
};


