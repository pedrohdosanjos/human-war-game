#include "Inimigo.h"

void Inimigo::initPhysics()
{
	this->velocityMax = 15.f;
	this->velocityMin = 1.f;
	this->acceleration = 3.f;
	this->drag = 0.8f;
	this->gravity = 4.f;
	this->velocityMaxY = 80.f;
}

Inimigo::Inimigo(ID id) :
	Personagem(id)
{
	this->initPhysics();
}

Inimigo::~Inimigo()
{
}

sf::Vector2f Inimigo::updateMovement(sf::Vector2f pos)
{
	this->animState = IDLE;

	if (this->getPosition().x - pos.x < 600 && this->getPosition().x > pos.x)
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

void Inimigo::collide(Entidade* otherEntity, sf::Vector2f intersect)
{
	if (otherEntity->getID() == platform)
	{
		this->moveOnCollision(intersect, otherEntity);
	}
	else if (otherEntity->getID() == fire)
	{
		//Function to give damage to player
	}
	else if (otherEntity->getID() == player)
	{
		this->moveOnCollision(intersect, otherEntity);
		//Function to give damage to player
	}
}