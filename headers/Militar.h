#pragma once
#include "Inimigo.h"

class Militar : public Inimigo
{
protected:
	//Protected Functions
	void initTexture();


public:
	//Constructor/Destructor
	Militar();
	~Militar();
};