#include "Jogo.h"
#include "Player.h"
#include "Soldado.h"
#include "Plataforma.h"


//Private function
void Jogo::initVariables()
{
	this->window = nullptr;
}

void Jogo::initWindow()
{
	this->videoMode.height = 720;
	this->videoMode.width = 1280;
	this->window = new sf::RenderWindow(this->videoMode, "Jogo", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void Jogo::initPlayer()
{
	this->player = new Player();
}

void Jogo::initEnemy()
{
	this->soldier = new Soldado();
	this->soldier->setPosition(this->window->getSize().x, this->window->getSize().y);
}

void Jogo::initPlat()
{
	this->platform = new Plataforma();
	this->platform->setPosition(640, 360);
}


//Constructor / Destructor
Jogo::Jogo()
{
	this->initVariables();
	this->initWindow();
	this->initPlayer();
	this->initEnemy();
	this->initPlat();
}

Jogo::~Jogo()
{
	delete this->window;
	delete this->player;
	delete this->soldier;
	delete this->platform;
}


//Accessors
const bool Jogo::running() const
{
	return this->window->isOpen();
}



//Functions
void Jogo::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		case sf::Event::KeyReleased:
			if (
				this->ev.key.code == sf::Keyboard::A ||
				this->ev.key.code == sf::Keyboard::D ||
				this->ev.key.code == sf::Keyboard::W ||
				this->ev.key.code == sf::Keyboard::S
				)
			{
				this->player->resetAnimationTimer();
				this->soldier->resetAnimationTimer();
			}
		}
	}
	this->updateCollision();
}

void Jogo::updateCharacs()
{
	this->soldier->updateMovement(this->player->updateMovement(sf::Vector2f(0, 0)));
	this->soldier->update();
	this->player->update();
}

void Jogo::renderPlayer()
{
	this->player->render(*this->window);
}

void Jogo::renderEnemy()
{
	this->soldier->render(*this->window);
}

void Jogo::renderPlat()
{
	this->platform->render(*this->window);
}

void Jogo::setView()
{
	//View settings
	this->view.setCenter(player->getPosition());
	this->view.setSize(sf::Vector2f(1280.f, 720.f));
}

void Jogo::updateCollision()
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

//funções da main

void Jogo::update()
{
	this->pollEvents();
	this->updateCharacs();
}

void Jogo::render()
{
	//View settings
	this->setView();

	//Clear
	this->window->clear();

	//View
	this->window->setView(this->view);

	//Draw game objects
	this->renderPlayer();
	this->renderEnemy();
	this->renderPlat();
	this->window->display();
}
