#include "Jogo.h"
#include "Player.h"
#include "Inimigo.h"


//Private function
void Jogo::initVariables()
{
	this->window = nullptr;
}

void Jogo::initPlayer()
{
	this->player = new Player();
}

void Jogo::initEnemy()
{
	this->enemy = new Inimigo();
	this->enemy->setPosition(this->window->getSize().x, this->window->getSize().y);
}

void Jogo::initWindow()
{
	this->videoMode.height = 720;
	this->videoMode.width = 1280;
	this->window = new sf::RenderWindow(this->videoMode, "Jogo", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}


//Constructor / Destructor
Jogo::Jogo()
{
	this->initVariables();
	this->initWindow();
	this->initPlayer();
	this->initEnemy();
}

Jogo::~Jogo()
{
	delete this->window;
	delete this->player;
	delete this->enemy;
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
				this->enemy->resetAnimationTimer();
			}
		}
	}
	this->updateCollision();
}

void Jogo::updateEnemy()
{
	this->enemy->updateMovement(this->player->updateMovement(sf::Vector2f(0, 0)));
	this->enemy->update();
	this->player->update();
}

void Jogo::updatePlayer()
{
}

void Jogo::renderPlayer()
{
	this->player->render(*this->window);
}


void Jogo::renderEnemy()
{
	this->enemy->render(*this->window);
}

void Jogo::update()
{
	this->pollEvents();
	this->updatePlayer();
	this->updateEnemy();
}

void Jogo::render()
{
	this->window->clear();


	//Draw game objects
	this->renderPlayer();
	this->renderEnemy();
	this->window->display();
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
	if (this->enemy->getPosition().y + this->enemy->getGlobalBounds().height > this->window->getSize().y)
	{
		this->enemy->canJump = true;
		this->enemy->resetVelocityY();

		this->enemy->setPosition(
			this->enemy->getPosition().x,
			this->window->getSize().y - this->enemy->getGlobalBounds().height);
	}
}