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

void Jogo::initPlayer()
{
	this->player = new Player();
	this->player->setPosition(0, 0);
}

void Jogo::initFase()
{
	this->fase1 = new Fase(this->player, graphicManager->getWindow());
}

//Constructor / Destructor
Jogo::Jogo() :
	graphicManager(GerenciadorGrafico::getInstance())
{
	this->initPlayer();
	this->initFase();
	this->initVariables();
}

Jogo::~Jogo()
{
	delete this->player;
	delete this->fase1;

}

//Accessors
const bool Jogo::running() const
{
	return graphicManager->isWindowOpen();
}

//Functions
void Jogo::pollEvents()
{
	while (graphicManager->getWindow()->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			graphicManager->closeWindow();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				graphicManager->closeWindow();
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
	graphicManager->centerView(player->getPosition());
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
	graphicManager->clear();

	//View
	//this->window->setView(this->view);

	//Draw game objects
	for (int i = 0; i < this->LEs->LEs.getSize(); i++)
	{
		Entidade* pAux = LEs->LEs.getItem(i);
		pAux->draw(*graphicManager->getWindow());
	}
	graphicManager->display();
}