#pragma once
#include "Entidade.h"

class Obstaculo: public Entidade
{
protected:

public:
	Obstaculo();
	~Obstaculo();

	virtual void initTexture() = 0;
	virtual void initSprite() = 0;
};

