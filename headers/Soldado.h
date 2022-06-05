#pragma once
#include "Inimigo.h"

class Soldado: public Inimigo
{
public:
	Soldado();
	~Soldado();

	void initTexture();
};
