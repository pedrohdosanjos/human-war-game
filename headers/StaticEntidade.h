#pragma once
#include"Entidade.h"

class StaticEntidade : public Entidade
{
public:
	//Constructor/Destructor
	StaticEntidade(ID id = empty);
	~StaticEntidade();

	//Public Functions
	virtual void initTexture() = 0;
	virtual void initSprite() = 0;
	virtual void collide(Entidade* otherEntity, sf::Vector2f collision);
};
