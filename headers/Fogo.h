#pragma once
#include"Obstaculo.h"

class Fogo : public Obstaculo
{
private:
	void initTexture();
	void initSprite();
public:
	//Constructor/Destructor
	Fogo(sf::Vector2f pos);
	~Fogo();
};