#include "ListaEntidades.h"
#include "Fase.h"
#include "Jogo.h"
#include "Player.h"
#include "Soldado.h"
#include "Plataforma.h"


//Private function
void Jogo::initVariables()
{
	this->LEs = fase1->getListaEntidades();
}

void Jogo::initWindow()
{
	this->videoMode.height = 720;
	this->videoMode.width = 1280;
	this->window = new sf::RenderWindow(this->videoMode, "THW", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void Jogo::initPlayer()
{
	this->player = new Player();
	this->player->setWindow(this->window);
}
void Jogo::initFase()
{
	this->fase1 = new Fase(this->player, this->player->getWindow());
}

//Constructor / Destructor
Jogo::Jogo()
{
	this->initWindow();
	this->initPlayer();
	this->initFase();
	this->initVariables();
	

}

Jogo::~Jogo()
{
	delete this->window;
	delete this->player;
	delete this->fase1;

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
				this->fase1->resetAnimationTimer(); 
			}
		}
	}
	this->fase1->updateCollision();
}


void Jogo::setView()
{
	//View settings
	this->view.setCenter(player->getPosition());
	this->view.setSize(sf::Vector2f(1280.f, 720.f));
}


//fun��es da main

void Jogo::update()
{
	this->pollEvents();
	this->fase1->updateCharacs();
}

void Jogo::render()
{
	//Collision
	this->fase1->checkCollision();

	//View settings
	this->setView();

	//Clear
	this->window->clear();

	//View
	this->window->setView(this->view);

	//Draw game objects
	for (int i = 0; i < this->LEs->LEs.getSize(); i++)
	{
		Entidade* pAux = LEs->LEs.getItem(i);
		pAux->draw(*this->window);
	}

	this->window->display();
}