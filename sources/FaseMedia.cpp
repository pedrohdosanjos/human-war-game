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

FaseMedia::FaseMedia(Player* j1):Fase()
{
	this->player = j1;

	initVariables();
	initPosition();
}

FaseMedia::~FaseMedia()
{
}


void FaseMedia::updateCharacs()
{
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
