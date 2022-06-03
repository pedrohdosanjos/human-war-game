#pragma once
#include "Personagem.h"

#define JUMPING_HEIGHT 200.f

class Player: public Personagem
{
public:

	sf::Vector2f updateMovement(sf::Vector2f pos);
	void initTexture();
	void initPhysics();

	//Constructor / Destructor
	Player();
	~Player();
};
