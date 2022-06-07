#pragma once
#include "Entidade.h"

class Obstaculo: public Entidade
{
protected:

public:
	//Constuctor/Destructor
	Obstaculo();
	~Obstaculo();

	//Public Functions
	virtual void initTexture() = 0;
	virtual void initSprite() = 0;

	//Collision Functions
	virtual void collide(Player* player, sf::Vector2f collision);
};

