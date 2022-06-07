#pragma once
#include "Entidade.h"

class Obstaculo : public Entidade
{
protected:
	//Protected Functions
	virtual void initTexture() = 0;
	virtual void initSprite() = 0;

public:
	//Constructor/Destructor
	Obstaculo();
	~Obstaculo();


};
