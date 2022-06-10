#pragma once
#include <SFML/Graphics.hpp>
class Player;
class Soldado;
class Plataforma;
class ListaEntidades;
#include "Collider.h"

/*
	No futuro essa ser� uma das fases(em espec�fico a Contemp) e n�o a classe fase pronta;
	A fase vai so chamar uma das duas e nelas serao instanciados os objetos da fase.
*/
class Fase
{
private:
	//Private Variables
	//ListaEntidades* listaEntidades;
	ListaEntidades* movingEntities;
	ListaEntidades* staticEntities;
	Plataforma* platform;
	Soldado* soldier;
	Player* player;
	Collider* collider;
	sf::RenderWindow* window;


	//Private Functions
	void initVariables();
	void initPosition();

public:
	//Constructor/Destructor
	Fase(Player* j1, sf::RenderWindow* window);
	~Fase();

	//Public Functions
	ListaEntidades* getListaMovingEntidades() { return movingEntities; }
	ListaEntidades* getListaStaticEntidades() { return staticEntities; }

	//Collision
	void updateCollision();
	void checkCollision();

	//Other Functions
	void updateCharacs();
	void resetAnimationTimer();
};