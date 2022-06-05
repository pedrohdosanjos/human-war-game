#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

#include <vector>
#include <iostream>
#include<ctime>
class Player;
class Soldado;
class Plataforma;

class Jogo
{
private:
	//Variables
	Player* player;
	Soldado* soldier;
	Plataforma* platform;

	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
	sf::View view;


	//Private functions
	void initVariables();
	void initWindow();
	void initPlayer();
	void initEnemy();
	void initPlat();


public:
	//Constructor / Destructor
	Jogo();
	virtual ~Jogo();

	//Accessors
	const bool running() const;

	//Functions
	void pollEvents();
	void updateCharacs();
	void renderPlayer();	
	void renderEnemy();
	void renderPlat();

	void setView();

	void update();
	void render();

	//Collision
	void updateCollision();
};