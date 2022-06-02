#pragma once
#include "Personagem.h"

#define JUMPING_HEIGHT 200.f

class Player: public Personagem
{
public:

	void initTexture();

	//Constructor / Destructor
	Player();
	~Player();

	sf::Vector2f updateMovement(sf::Vector2f pos);
};
