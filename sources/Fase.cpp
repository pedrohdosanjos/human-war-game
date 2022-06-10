#include "Fase.h"
#include "Player.h"
#include "Soldado.h"
#include "Plataforma.h"
#include "ListaEntidades.h"

void Fase::initVariables()
{
	movingEntities->LEs.push(this->player);
	movingEntities->LEs.push(this->soldier);

	//worldGen.generate(&posRender, player);

	collider = new Collider(movingEntities, staticEntities);
}

void Fase::initPosition()
{
	this->soldier->setPosition(1580, 0);
	this->player->setPosition(300, 0);
}

Fase::Fase(Player* j1, sf::RenderWindow* window):
	movingEntities(new ListaEntidades()),
	staticEntities(new ListaEntidades()),
	worldGen(movingEntities, staticEntities)
{
	this->window = window;
	this->player = j1;
	this->soldier = new Soldado();

	initVariables();
	initPosition();
}

Fase::~Fase()
{
}


void Fase::updateCollision()
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


void Fase::checkCollision()
{
	this->collider->collide();

}

void Fase::updateCharacs()
{
	this->soldier->updateMovement(this->player->updateMovement(sf::Vector2f(0, 0)));
	this->soldier->update();
	this->player->update();

	if(this->player->getPosition().x > posRender.x)
		worldGen.generate(&posRender, player);
}


void Fase::resetAnimationTimer()
{
	this->player->resetAnimationTimer();
	this->soldier->resetAnimationTimer();
}