#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include "GerenciadorGrafico.h"

#include <vector>
#include <iostream>
#include<ctime>

class Menu;
class Fase;
class FaseMedia;
class FaseContemp;
class ListaEntidades;
class Player;
class Soldado;
class Plataforma;

class Jogo
{
private:

	//Manager
	GerenciadorGrafico* graphicManager;

	//Variables
	Player* player;
	ListaEntidades* LMEs;
	ListaEntidades* LSEs;	
	Fase* fase;
	int numFase;

	//Window
	sf::Event ev;

	//Private functions
	void initVariables();
	void initPlayer();
	void initFase();

public:
	//Constructor / Destructor
	Jogo();
	virtual ~Jogo();

	//Menu
	Menu* menu;

	//Accessors
	const bool running() const;

	//Functions
	void pollEvents();

	//View Setting
	void setView();

	//Game loop
	void update();
	void render();

};