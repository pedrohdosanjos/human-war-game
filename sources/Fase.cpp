#include "Fase.h"
#include "Soldado.h"
#include "Plataforma.h"
#include "ListaEntidades.h"

void Fase::initVariables()
{
	listaEntidades->LEs.push(player);
	listaEntidades->LEs.push(soldier);
	listaEntidades->LEs.push(platform);
}

void Fase::initPosition()
{
	this->soldier->setPosition(1280, 720);
	this->platform->setPosition(500.f, 450.f);
}

Fase::Fase(Player* j1, sf::RenderWindow* window):worldGen(listaEntidades)
{
	this->window = window;
	this->player = j1;
	this->listaEntidades = new ListaEntidades();
	this->soldier = new Soldado();

	proxRender = sf::Vector2f(0, 0);
	worldGen.resetToOrigin();
	//worldGen.generate(&proxRender, player);

	this->platform = new Plataforma(sf::Vector2f(0,0));
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
	//Colliding Player and Platform
	sf::Vector2f centerDist;
	sf::Vector2f collision;


	centerDist.x = player->getPosition().x - platform->getPosition().x;
	centerDist.y = player->getPosition().y - platform->getPosition().y;

	collision.x = abs(centerDist.x) - (this->player->getSize().x / 2.0f + this->platform->getSize().x / 2.0f);
	collision.y = abs(centerDist.y) - (this->player->getSize().y / 2.0f + this->platform->getSize().y / 2.0f);


	if (collision.x < 0.0f && collision.y < 0.0f)
	{
		if (collision.x > collision.y)
		{
			if (centerDist.x > 0.0f)
			{
				this->player->setPosition(this->player->getPosition().x - collision.x, this->player->getPosition().y);
			}
			else
			{
				this->player->setPosition(this->player->getPosition().x + collision.x, this->player->getPosition().y);
			}
			this->player->resetVelocityX();
		}
		else
		{
			if (centerDist.y > 0.0f)
			{
				this->player->setPosition(this->player->getPosition().x, this->player->getPosition().y - collision.y);
			}
			else
			{
				this->player->setPosition(this->player->getPosition().x, this->player->getPosition().y + collision.y);
			}
			this->player->resetVelocityY();
			this->player->canJump = true;
		}
	}

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