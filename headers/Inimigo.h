#pragma once
#include "Personagem.h"

class Inimigo : public Personagem::Personagem
{
protected:

	//Protected Functions
	virtual void initSprite() = 0;
	virtual void initTexture() = 0;
	void initPhysics();

public:

	//Constructor / Destructor
	Inimigo(ID id = empty);
	~Inimigo();

	//Public Functions
	sf::Vector2f updateMovement(sf::Vector2f pos);

	//Collision
	void collide(Entidade* otherEntity, sf::Vector2f intersect);

};