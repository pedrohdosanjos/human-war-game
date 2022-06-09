#pragma once
#include <SFML/Graphics.hpp>
#include "GeradorDeMundo.h"

class Player;
class Soldado;
class Plataforma;
class ListaEntidades;

/*
	No futuro essa ser� uma das fases(em espec�fico a Contemp) e n�o a classe fase pronta;
	A fase vai so chamar uma das duas e nelas serao instanciados os objetos da fase.
*/
class Fase
{
private:
	//Private Variables
	ListaEntidades* listaEntidades;
	Plataforma* platform;
	Soldado* soldier;
	Player* player;
	sf::RenderWindow* window;

	GeradorDeMundo worldGen;
	sf::Vector2f proxRender;

	//Private Functions
	void initVariables();
	void initPosition();

public:
	//Constructor/Destructor
	Fase();
	Fase(Player* j1, sf::RenderWindow* window);
	~Fase();

	//Public Functions
	ListaEntidades* getListaEntidades() { return listaEntidades; };

	//Collision
	void updateCollision();
	void checkCollision();

	//Other Functions
	void updateCharacs();
	void resetAnimationTimer();
};