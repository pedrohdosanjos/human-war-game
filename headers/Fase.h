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

public:
	//Constructor/Destructor
	Fase();
	~Fase();

	void checkCollision();

	//Public Functions
	ListaEntidades* getListaMovingEntidades() { return movingEntities; }
	ListaEntidades* getListaStaticEntidades() { return staticEntities; }

	virtual void updateCharacs() = 0;
	virtual void resetAnimationTimer() = 0;
};