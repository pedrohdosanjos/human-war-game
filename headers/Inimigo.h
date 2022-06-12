#pragma once
#include "Personagem.h"
class Player;

class Inimigo : public Personagem
{

private:

	Player* pPlayer;

protected:

	//Protected Functions
	virtual void initTexture() = 0;
	virtual void initSprite() = 0;
	void initPhysics();

public:

	//Constructor / Destructor
	Inimigo(Player* pP,int life = 1, const float attCooldown = 1.0f, const float attackingTime = 0.0f, ID id = empty); //Default Values
	~Inimigo();

	//Public Functions
	sf::Vector2f updateMovement(sf::Vector2f pos);

	//Collision
	void collide(Entidade* otherEntity, sf::Vector2f intersect);

	//Relating to Player
	void setpPlayer(Player* pP);
	sf::Vector2f getPlayerPosition();

	//Damage
	void receiveDamage(const int damage);

};