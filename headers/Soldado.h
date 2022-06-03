#pragma once
#include "Inimigo.h"

class Soldado : public Inimigo
{
private:
	//Private Functions
	void initTexture();

public:
	//Constructor/Destructor
	Soldado();
	~Soldado();

};