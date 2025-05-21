#include "Personagem.h"
#include <cmath>

void Personagem::Personagem::initVariables()
{
	this->animState = IDLE;
}

void Personagem::Personagem::initAnimations()
{
	this->animationTimer.restart();
	this->animationSwitch = true; // default
}

Personagem::Personagem::Personagem(ID id) : MovingEntidade(id)
{
	this->initVariables();
	this->initAnimations();
}

Personagem::Personagem::~Personagem()
{
}

const sf::FloatRect Personagem::Personagem::getGlobalBounds() const
{
	return this->sprite.getGlobalBounds();
}

const bool &Personagem::Personagem::getAnimSwitch()
{
	bool anim_switch = this->animationSwitch;

	if (this->animationSwitch)
		this->animationSwitch = false;

	return this->animationSwitch;
}

void Personagem::Personagem::resetVelocityY()
{
	this->velocity.y = 0.f;
}

void Personagem::Personagem::resetVelocityX()
{
	this->velocity.x = 0.f;
}

void Personagem::Personagem::move(const float x, const float y)
{
	if (x != 0)
	{
		// Acceleration
		this->velocity.x += x * this->acceleration;

		// Limit velocity
		if (std::abs(this->velocity.x) > this->velocityMax)
		{
			this->velocity.x = this->velocityMax * ((this->velocity.x < 0.f) ? -1.f : 1.f); // Checando a dire��o do movimento
		}
	}
	else
	{
		// Jumping
		this->velocity.y = -sqrt(y * 980.f * JUMPING_HEIGHT);
	}
}

void Personagem::Personagem::updateAnimations()
{
	if (this->animState == IDLE)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f || this->getAnimSwitch())
		{
			this->currentFrame.top = 0.f;
			this->currentFrame.left += 40.f;

			if (this->currentFrame.left >= 160.f) // valor usado para o png em quest�o
			{
				this->currentFrame.left = 0; // Reiniciando a anima��o
			}

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animState == MOVING_RIGHT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
		{
			this->currentFrame.top = 50.f;
			this->currentFrame.left += 40.f;

			if (this->currentFrame.left >= 360.f) // valor usado para o png em quest�o
			{
				this->currentFrame.left = 0; // Reiniciando a anima��o
			}

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}

		this->sprite.setScale(3.f, 3.f);
		this->sprite.setOrigin(0.f, 0.f);
	}
	else if (this->animState == MOVING_LEFT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f)
		{
			this->currentFrame.top = 50.f;
			this->currentFrame.left += 40.f;

			if (this->currentFrame.left >= 360.f) // valor usado para o png em quest�o
			{
				this->currentFrame.left = 0; // Reiniciando a anima��o
			}

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}

		this->sprite.setScale(-3.f, 3.f);
		this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 3.f, 0.f);
	}
	else if (this->animState == JUMPING)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.3f)
		{
			this->currentFrame.top = 100.f;
			this->currentFrame.left += 80.f;

			if (this->currentFrame.left >= 80.f) // valor usado para o png em quest�o
			{
				this->currentFrame.left = 0; // Reiniciando a anima��o
			}

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}

	else
	{
		this->animationTimer.restart();
	}
}

void Personagem::Personagem::resetAnimationTimer()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void Personagem::Personagem::updatePhysics()
{

	// Gravity
	this->velocity.y += 1.0 * this->gravity;

	// Limit gravity
	if (std::abs(this->velocity.y) > this->velocityMaxY)
	{
		this->velocity.y = this->velocityMaxY * ((this->velocity.y < 0.f) ? -1.f : 1.f); // Checando a dire��o do movimento
	}

	// Deceleration
	this->velocity *= this->drag;

	// Limit deceleration
	if (std::abs(this->velocity.x) < this->velocityMin)
	{
		this->velocity.x = 0.f;
	}
	if (std::abs(this->velocity.y) < this->velocityMin)
	{
		this->velocity.y = 0.f;
	}
	this->sprite.move(this->velocity);
}

void Personagem::Personagem::update()
{
	this->updateAnimations();
	this->updatePhysics();
}