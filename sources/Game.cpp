#include "Game.h"
#include "Player.h"



//Private function
void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initPlayer()
{
	this->player = new Player();
}

void Game::initWindow()
{
	this->videoMode.height = 720;
	this->videoMode.width = 1280;
	this->window = new sf::RenderWindow(this->videoMode, "Player", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}


//Constructor / Destructor
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initPlayer();
}

Game::~Game()
{
	delete this->window;
	delete this->player;
}

//Accessors
const bool Game::running() const
{
	return this->window->isOpen();
}



//Functions


void Game::pollEvents()
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
			}


		}

	}
	this->updateCollision();
}


void Game::updatePlayer()
{
	this->player->update();
}

void Game::renderPlayer()
{
	this->player->render(*this->window);
}

void Game::update()
{
	this->pollEvents();
	this->updatePlayer();
}



void Game::render()
{
	this->window->clear();


	//Draw game objects
	this->renderPlayer();
	this->window->display();
}

void Game::updateCollision()
{
	//Collision bottom of screen
	if (this->player->getPosition().y + this->player->getGlobalBounds().height > this->window->getSize().y)
	{
		this->player->resetVelocityY();

		this->player->setPosition(
			this->player->getPosition().x,
			this->window->getSize().y - this->player->getGlobalBounds().height);
	}
}
