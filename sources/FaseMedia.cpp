#include "FaseMedia.h"

void FaseMedia::initVariables()
{
	movingEntities->LEs.push(this->player);

	this->collider = new Collider(movingEntities, staticEntities);
}

void FaseMedia::initPosition()
{
	this->player->setPosition(450, 0);
}

FaseMedia::FaseMedia(Player* j1) :Fase()
{
	this->player = j1;

	initVariables();
	initPosition();
}

FaseMedia::~FaseMedia()
{
}

void FaseMedia::updateCollision()
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
	if (this->soldier->getPosition().y + this->soldier->getGlobalBounds().height > 720)
	{
		this->soldier->resetVelocityY();

		this->soldier->setPosition(
			this->soldier->getPosition().x,
			720 - this->soldier->getGlobalBounds().height);
	}
}

void FaseMedia::updateCharacs(const float dt)
{
	//Errado
	for (int i = 0; i < movingEntities->LEs.getSize(); i++)
	{
		movingEntities->LEs.getItem(i)->updateMovement(this->player->updateMovement(sf::Vector2f(0, 0)));
		movingEntities->LEs.getItem(i)->update();

	}

	if (this->player->getPosition().x > posRender.x)
		worldGen.generate(&posRender, player, 1);
}

void FaseMedia::resetAnimationTimer()
{

	for (int i = 0; i < movingEntities->LEs.getSize(); i++)
	{
		movingEntities->LEs.getItem(i)->resetAnimationTimer();

	}
}