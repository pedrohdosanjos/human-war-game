#pragma once
#include "Inimigo.h"

class Militar : public Inimigo
{
protected:
	//Protected Functions
	void initTexture();
	void initSprite();


public:
	//Constructor/Destructor
	Militar(int pos, Player* pP = nullptr);
	~Militar();

	//Update
	void update(const float dt);
};