#pragma once
#include "Soldado.h"
#include "Fogo.h"
#include "Fase.h"

class FaseMedia: public Fase
{
private:
	//Class Variables
	Soldado* soldier;

	//Private Functions
	void initVariables();
	void initPosition();

public:
	//Constructor/Destructor
	FaseMedia(Player* j1);
	~FaseMedia();

	//Collision
	void updateCollision();

	//Other Functions
	void updateCharacs();
	void resetAnimationTimer();
};