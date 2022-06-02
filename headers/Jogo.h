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
class Inimigo;

class Jogo
{
private:
	//Variables
	Player* player;
	Inimigo* enemy;


	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;


	//Private functions
	void initVariables();
	void initWindow();
	void initPlayer();
	void initEnemy();


public:
	//Constructor / Destructor
	Jogo();
	virtual ~Jogo();

	//Accessors
	const bool running() const;

	//Functions
	void pollEvents();
	void updatePlayer();
	void renderPlayer();
	void updateEnemy();
	void renderEnemy();
	void update();
	void render();

	//Collision
	void updateCollision();
};