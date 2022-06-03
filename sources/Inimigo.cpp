#include "Inimigo.h"

sf::Vector2f Inimigo::updateMovement(sf::Vector2f pos)
{
	this->animState = IDLE;

	if (this->getPosition().x > pos.x)
	{
		this->move(-1.f, 0.f);
		this->animState = MOVING_LEFT;
	}

	else if (this->getPosition().x < pos.x)
	{
		this->move(1.f, 0.f);
		this->animState = MOVING_RIGHT;
	}

	return pos;
}

void Inimigo::initPhysics()
{
	this->velocityMax = 10.f;
	this->velocityMin = 1.f;
	this->acceleration = 3.f;
	this->drag = 0.8f;
	this->gravity = 4.f;
	this->velocityMaxY = 80.f;
}

Inimigo::Inimigo(): Personagem()
{
	this->initPhysics();
}

Inimigo::~Inimigo()
{
}

