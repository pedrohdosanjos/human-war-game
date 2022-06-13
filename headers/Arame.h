#pragma once
#include "Obstaculo.h"

class Arame :public Obstaculo
{
private:
	void initTexture();
	void initSprite();

public:
	//Constructor/Destructor
	Arame(sf::Vector2f pos);
	~Arame();
};