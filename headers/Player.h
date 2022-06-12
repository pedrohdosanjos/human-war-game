#pragma once
#include "Personagem.h"


class Player : public Personagem
{
private:
	const float swordDistance;
	float damageCooldown;

protected:

	//Protected Functions
	void initTexture();
	void initSprite();
	void initPhysics();

public:

	//Constructor / Destructor
	Player();
	~Player();

	//Public Functions
	sf::Vector2f updateMovement(sf::Vector2f pos);

	//Collision
	void collide(Entidade* otherEntity, sf::Vector2f collision);

	//Update
	void update(const float dt);

	//Game Mechanics
	const float getSwordDistance();
	void receiveDamage(const int damage);

};