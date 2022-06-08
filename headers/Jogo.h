#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

#include <vector>
#include <iostream>
#include<ctime>

class Fase;
class ListaEntidades;
class Player;
class Soldado;
class Plataforma;

class Jogo
{
private:
	//Variables
	Player* player;
	ListaEntidades* LEs;
	Fase* fase1;

	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
	sf::View view;

	

	//Private functions
	void initVariables();
	void initWindow();
	void initPlayer();
	void initFase();



public:
	//Constructor / Destructor
	Jogo();
	virtual ~Jogo();

	//Accessors
	const bool running() const;

	//Functions
	void pollEvents();


	void setView();

	void update();
	void render();

};