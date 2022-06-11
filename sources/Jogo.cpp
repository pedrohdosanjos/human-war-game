#include "ListaEntidades.h"
#include "FaseMedia.h"
#include "FaseContemp.h"
#include "Jogo.h"
#include "Player.h"
#include "Soldado.h"
#include "Plataforma.h"
#include "Menu.h"

//Private function
void Jogo::initVariables()
{
	this->LMEs = fase->getListaMovingEntidades();

	this->LSEs = fase->getListaStaticEntidades();

}


void Jogo::initPlayer()
{
	this->player = new Player();
}


void Jogo::initFase()
{
	numFase = menu->selectedFase;

	if (numFase == 1)
		fase = new FaseMedia(this->player);

	else if (numFase == 2)
		fase = new FaseContemp(this->player);

	else
		std::cout << "burro";
}


//Constructor / Destructor
Jogo::Jogo() :
	graphicManager(GerenciadorGrafico::getInstance())
{
	this->menu = new Menu();

	while (this->menu->selectedFase == 0)
	{
		this->menu->run_menu();
	}

	this->initPlayer();
	this->initFase();
	this->initVariables();
}


Jogo::~Jogo()
{
	delete this->player;
	delete this->fase;
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
				this->fase->resetAnimationTimer();
			}
		}
	}
	//this->fase1->updateCollision();
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
	this->fase->updateCharacs();
}

void Jogo::render()
{
	//Update Delta Time
	this->graphicManager->updateDeltaTime();

	//Collision
	this->fase->checkCollision();

	//View settings
	this->setView();

	//Clear
	graphicManager->clear();

	//Draw game objects
	for (int i = 0; i < this->LMEs->LEs.getSize(); i++) //Moving Entities
	{
		Entidade* pAux = LMEs->LEs.getItem(i);
		pAux->draw(*graphicManager->getWindow());

	}

	for (int i = 0; i < this->LSEs->LEs.getSize(); i++) //Static Entities
	{
		Entidade* pAux = LSEs->LEs.getItem(i);
		pAux->draw(*graphicManager->getWindow());

	}
	graphicManager->display();
}