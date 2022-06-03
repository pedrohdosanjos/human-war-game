#pragma once
#include "Personagem.h"

class Inimigo: public Personagem
{
public:

	sf::Vector2f updateMovement(sf::Vector2f pos);
	virtual void initTexture() = 0;
	void initPhysics();

	//Constructor / Destructor
	Inimigo();
	~Inimigo();


};