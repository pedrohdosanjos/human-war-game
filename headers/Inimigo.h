#pragma once
#include "Personagem.h"

class Inimigo : public Personagem
{
protected:

	//Protected Functions
	virtual void initTexture();
	void initSprite();
	void initPhysics();

public:

	//Constructor / Destructor
	Inimigo();
	~Inimigo();

	//Public Functions
	sf::Vector2f updateMovement(sf::Vector2f pos);

};