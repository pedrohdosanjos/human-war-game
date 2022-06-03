#pragma once
#include "Personagem.h"

class Inimigo : public Personagem
{

private:
	//Funções Privadas
	virtual void initTexture();
	void initPhysics();


public:
	//Funções Públicas
	sf::Vector2f updateMovement(sf::Vector2f pos);


	//Constructor / Destructor
	Inimigo();
	~Inimigo();


};