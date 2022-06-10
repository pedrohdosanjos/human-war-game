#pragma once
#include "Obstaculo.h"

class Plataforma :public Obstaculo
{
public:
	//Constructor/Destructor
	Plataforma();
	~Plataforma();

	//Public Functions
	void initTexture();
	void initSprite();

};