#pragma once
#include "Inimigo.h"

class Soldado : public Inimigo
{
protected:
	//Protected Functions
	void initTexture();
	void initSprite();

public:
	//Constructor/Destructor
	Soldado(int pos, Player* pP = nullptr);
	~Soldado();

	//Update
	void update(const float dt);

};