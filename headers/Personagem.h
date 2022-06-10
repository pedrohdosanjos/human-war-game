#pragma once
#include "MovingEntidade.h"


#define JUMPING_HEIGHT 200.f

enum PLAYER_ANIMATION_STATES { IDLE = 0, MOVING_LEFT, MOVING_RIGHT, JUMPING, FALLING };

class Personagem : public MovingEntidade
{
protected:
	sf::Clock animationTimer;

	//Animation
	bool animationSwitch;
	short animState;

	//Physics
	//sf::Vector2f velocity;
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
	void initVariables();
	void initAnimations();


public:

	//Constructor / Destructor
	Personagem(ID id = empty);
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
	void update();
};