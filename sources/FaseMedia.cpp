#include "FaseMedia.h"

void FaseMedia::initVariables()
{
	movingEntities->LEs.push(this->player);
	movingEntities->LEs.push(this->soldier);

	this->collider = new Collider(movingEntities, staticEntities);
}

void FaseMedia::initPosition()
{
	this->player->setPosition(450, 0);
}

FaseMedia::FaseMedia(Player* j1) :Fase()
{
	this->player = j1;
	this->soldier = new Soldado(1530);

	initVariables();
	initPosition();
}

FaseMedia::~FaseMedia()
{
}


void FaseMedia::updateCharacs()
{
	this->soldier->updateMovement(this->player->updateMovement(sf::Vector2f(0, 0)));
	this->soldier->update();
	this->player->update();

	if (this->player->getPosition().x > posRender.x)
		worldGen.generate(&posRender, player, 1);
}

void FaseMedia::resetAnimationTimer()
{
	this->player->resetAnimationTimer();
	this->soldier->resetAnimationTimer();
}