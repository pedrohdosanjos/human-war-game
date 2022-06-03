#pragma once
#include "Personagem.h"

#define JUMPING_HEIGHT 200.f

class Player : public Personagem
{
private:
	//Private functions
	void initTexture();
	void initPhysics();

public:
	//Constructor / Destructor
	Player();
	~Player();

	//Public Functions
	sf::Vector2f updateMovement(sf::Vector2f pos);
};