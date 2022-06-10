#pragma once
#include "Obstaculo.h"

class Plataforma :public Obstaculo
{
public:
	//Constructor/Destructor
	Plataforma(sf::Vector2f pos);
	~Plataforma();

	//Public Functions
	void initTexture();
	void initSprite();

};