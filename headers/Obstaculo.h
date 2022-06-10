#pragma once
#include "StaticEntidade.h"

class Obstaculo : public StaticEntidade
{
protected:
	//Protected Functions
	virtual void initTexture() = 0;
	virtual void initSprite() = 0;

public:
	//Constructor/Destructor
	Obstaculo(ID id = empty);
	~Obstaculo();


};
