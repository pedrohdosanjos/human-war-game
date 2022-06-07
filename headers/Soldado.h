#pragma once
#include "Inimigo.h"

class Soldado : public Inimigo
{
protected:
	//Protected Functions
	void initTexture();

public:
	//Constructor/Destructor
	Soldado();
	~Soldado();

};