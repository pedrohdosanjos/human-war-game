#include "Fase.h"
#include "Player.h"
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
	this->soldier->setPosition(this->soldier->getWindow()->getSize().x, this->soldier->getWindow()->getSize().y);
	this->platform->setPosition(500.f, 450.f);
}

void Fase::initWindow()
{
	this->soldier->setWindow(this->window);
	this->platform->setWindow(this->window);
}

Fase::Fase(Player* j1, sf::RenderWindow* window)
{
	this->window = window;
	this->player = j1;
	this->listaEntidades = new ListaEntidades();
	this->soldier = new Soldado();
	this->platform = new Plataforma();
	initVariables();
	initWindow();
	initPosition();
}

Fase::~Fase()
{
}

void Fase::updateCollision()
{
	//Collision bottom of screen
	if (this->player->getPosition().y + this->player->getGlobalBounds().height > this->window->getSize().y)
	{
		this->player->canJump = true;
		this->player->resetVelocityY();

		this->player->setPosition(
			this->player->getPosition().x,
			this->window->getSize().y - this->player->getGlobalBounds().height);
	}
	if (this->soldier->getPosition().y + this->soldier->getGlobalBounds().height > this->window->getSize().y)
	{
		this->soldier->resetVelocityY();

		this->soldier->setPosition(
			this->soldier->getPosition().x,
			this->window->getSize().y - this->soldier->getGlobalBounds().height);
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

