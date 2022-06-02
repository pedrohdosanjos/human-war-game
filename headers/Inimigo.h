#pragma once
#include "Personagem.h"

class Inimigo: public Personagem
{
public:
	void initTexture();

	//Constructor / Destructor
	Inimigo();
	~Inimigo();

	sf::Vector2f updateMovement(sf::Vector2f pos) ;
};