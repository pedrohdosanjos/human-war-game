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

class Game
{
private:
	//Variables
	Player* player;


	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;


	//Private functions
	void initVariables();
	void initWindow();
	void initPlayer();


public:
	//Constructor / Destructor
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;

	//Functions
	void pollEvents();
	void updatePlayer();
	void renderPlayer();
	void update();
	void render();

	//Collision
	void updateCollision();
};

