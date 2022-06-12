#pragma once
#include"Entidade.h"

class MovingEntidade:public Entidade
{
protected:
	bool alive;
	int damage;

public:
	//Constructor/Destructor
	MovingEntidade(ID id = empty);
	~MovingEntidade();


	//Virtual Functions
	virtual void initTexture() = 0;
	virtual void initSprite() = 0;
	virtual void resetAnimationTimer() = 0;

	//Public Functions
	virtual sf::Vector2f updateMovement(sf::Vector2f pos) = 0;
	virtual void collide(Entidade* otherEntity, sf::Vector2f intersect) = 0;
	void moveOnCollision(sf::Vector2f collision, Entidade* other);

	//Velocity Variable
	sf::Vector2f velocity;

	//Update
	virtual void update(const float dt) = 0;

	//Damage
	
	void setDamage(int damage);
	const int getDamage() const;


};

