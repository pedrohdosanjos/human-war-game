#pragma once
#include "MovingEntidade.h"


#define JUMPING_HEIGHT 200.0f

enum PLAYER_ANIMATION_STATES { IDLE = 0, MOVING_LEFT, MOVING_RIGHT, JUMPING, ATTACKING };

class Personagem : public MovingEntidade
{
protected:
	//Variables
	int life;
	bool flagIsAttacking;
	bool flagHasAttacked;
	const float attCooldown;
	const float attackingTime;
	float attackTimer;
	float cooldownTimer;


	//Animation
	sf::Clock animationTimer;
	bool animationSwitch;
	short animState;

	//Physics
	float velocityMax;
	float velocityMin;
	float acceleration;
	float drag;
	float gravity;
	float velocityMaxY;

	//Core
	virtual void initPhysics() = 0;
	virtual void initTexture() = 0;
	virtual void initSprite() = 0;
	void initAnimations();


public:

	//Constructor / Destructor
	Personagem(int life, const float attCooldown, const float attackingTime, ID id = empty);
	~Personagem();


	//Accessors
	const sf::FloatRect getGlobalBounds() const;
	const bool& getAnimSwitch();
	bool canJump;


	//Modifiers
	void resetVelocityY();
	void resetVelocityX();


	//Functions
	virtual sf::Vector2f updateMovement(sf::Vector2f pos) = 0;
	void move(const float x, const float y);
	void resetAnimationTimer();
	void updateAnimations();
	void updatePhysics();

	//Update
	virtual void update(const float dt);

	//Game Mechanics
	const int getLife() const;

	/*
	* Virtual function, because each type of character receive damage
	* and attack in different ways.
	*/
	virtual void receiveDamage(const int damage);
	virtual void attack();

	void incrementAttackingTimer(const float dt);
	const bool canAttack() const;
	const bool isAttacking() const;
	int getDamage();

};