#pragma once
#include "Militar.h"
#include "Arame.h"
#include "Fase.h"

class FaseContemp : public Fase
{
private:
	//Class Variables
	Militar* army;

	//Private Functions
	void initVariables();
	void initPosition();

public:
	//Constructor/Destructor
	FaseContemp(Player* j1);
	~FaseContemp();

	//Collision
	void updateCollision();

	//Other Functions
	void updateCharacs();
	void resetAnimationTimer();
};