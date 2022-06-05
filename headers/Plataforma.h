#pragma once
#include "Obstaculo.h"

class Plataforma :public Obstaculo
{
public: 
	Plataforma();
	~Plataforma();

	void initTexture();
	void initSprite();
};

