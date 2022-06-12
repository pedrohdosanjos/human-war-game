#pragma once
#include <SFML/Graphics.hpp>
class Player;
class Soldado;
class Plataforma;
class ListaEntidades;
#include "Collider.h"
#include "GeradorDeMundo.h"


class Fase
{
protected:
	//Private Variables
	ListaEntidades* movingEntities;
	ListaEntidades* staticEntities;

	Player* player;
	Collider* collider;

	GeradorDeMundo worldGen;
	sf::Vector2f posRender;


	//Private Functions
	virtual void initVariables() = 0;
	virtual void initPosition() = 0;

public:
	//Constructor/Destructor
	Fase();
	~Fase();

	//Public Functions
	ListaEntidades* getListaMovingEntidades() { return movingEntities; }
	ListaEntidades* getListaStaticEntidades() { return staticEntities; }

	//Collision
	void checkCollision();

	//Other Functions
	virtual void updateCharacs(const float dt) = 0;
	virtual void resetAnimationTimer() = 0;
};