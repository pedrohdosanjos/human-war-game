#include "FaseContemp.h"

void FaseContemp::initVariables()
{
	movingEntities->LEs.push(this->player);

	this->collider = new Collider(movingEntities, staticEntities);
}

void FaseContemp::initPosition()
{
	this->player->setPosition(450, 0);
}

FaseContemp::FaseContemp(Player* j1) :Fase()
{
	this->player = j1;

	initVariables();
	initPosition();
}

FaseContemp::~FaseContemp()
{
}

void FaseContemp::updateCollision()
{
	//Collision bottom of screen
	if (this->player->getPosition().y + this->player->getGlobalBounds().height > 720)
	{
		this->player->canJump = true;
		this->player->resetVelocityY();

		this->player->setPosition(
			this->player->getPosition().x,
			720 - this->player->getGlobalBounds().height);
	}
	if (this->army->getPosition().y + this->army->getGlobalBounds().height > 720)
	{
		this->army->resetVelocityY();

		this->army->setPosition(
			this->army->getPosition().x,
			720 - this->army->getGlobalBounds().height);
	}
}


void FaseContemp::updateCharacs(const float dt)
{
	this->army->updateMovement(this->player->updateMovement(sf::Vector2f(0, 0)));
	this->army->update(dt);
	this->player->update(dt);

	if (this->player->getPosition().x > posRender.x)
		worldGen.generate(&posRender, player, 2);
}

void FaseContemp::resetAnimationTimer()
{
	this->player->resetAnimationTimer();
	this->army->resetAnimationTimer();
}