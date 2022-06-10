#include "Fase.h"
#include "Player.h"
#include "Soldado.h"
#include "Plataforma.h"
#include "ListaEntidades.h"

void Fase::initVariables()
{
	movingEntities->LEs.push(this->player);
	movingEntities->LEs.push(this->soldier);
	staticEntities->LEs.push(this->platform);

	collider = new Collider(movingEntities, staticEntities);
}

void Fase::initPosition()
{
	this->soldier->setPosition(1280, 720);
	this->platform->setPosition(500.f, 450.f);
}

Fase::Fase(Player* j1, sf::RenderWindow* window)
{
	this->window = window;
	this->player = j1;
	this->movingEntities = new ListaEntidades();
	this->staticEntities = new ListaEntidades();
	this->soldier = new Soldado();
	this->platform = new Plataforma();
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
}


void Fase::resetAnimationTimer()
{
	this->player->resetAnimationTimer();
	this->soldier->resetAnimationTimer();
}