#include "Personagem.h"

void Personagem::initVariables()
{
	this->animState = IDLE;

}

void Personagem::initSprite()
{
	this->sprite.setTexture(this->textureSheet);
	this->currentFrame = sf::IntRect(0, 0, 40, 50); //40 por 50 

	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(3.f, 3.f);
}

void Personagem::initAnimations()
{
	this->animationTimer.restart();
	this->animationSwitch = true; //default
}

Personagem::Personagem()
{
	this->initVariables();
	this->initSprite();
	this->initAnimations();
}

Personagem::~Personagem()
{
}

const bool& Personagem::getAnimSwitch()
{
	bool anim_switch = this->animationSwitch;

	if (this->animationSwitch)
		this->animationSwitch = false;

	return anim_switch;
}

const sf::FloatRect Personagem::getGlobalBounds() const
{
	return this->sprite.getGlobalBounds();
}

const sf::Vector2f Personagem::getPosition() const
{
	return this->sprite.getPosition();
}

void Personagem::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Personagem::resetVelocityY()
{
	this->velocity.y = 0.f;
}

void Personagem::updateAnimations()
{
	if (this->animState == IDLE)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f || this->getAnimSwitch())
		{
			this->currentFrame.top = 0.f;
			this->currentFrame.left += 40.f;

			if (this->currentFrame.left >= 160.f) //valor usado para o png em questão
			{
				this->currentFrame.left = 0; //Reiniciando a animação
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

			if (this->currentFrame.left >= 360.f) //valor usado para o png em questão
			{
				this->currentFrame.left = 0; //Reiniciando a animação
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

			if (this->currentFrame.left >= 360.f) //valor usado para o png em questão
			{
				this->currentFrame.left = 0; //Reiniciando a animação
			}

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}

		this->sprite.setScale(-3.f, 3.f);
		this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 3.f, 0.f);
	}

	else
	{
		this->animationTimer.restart();
	}



}

void Personagem::update()
{
	//this->updateMovement(0);
	this->updateAnimations();
	this->updatePhysics();
}

void Personagem::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}

void Personagem::resetAnimationTimer()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void Personagem::move(const float x, const float y)
{
	//Acceleration
	this->velocity.x += x * this->acceleration;



	//Limit velocity
	if (std::abs(this->velocity.x) > this->velocityMax)
	{
		this->velocity.x = this->velocityMax * ((this->velocity.x < 0.f) ? -1.f : 1.f); //Checando a direção do movimento
	}

	//Jumping 
	this->velocity.y = -sqrt(y * 980.f * JUMPING_HEIGHT);
}

void Personagem::updatePhysics()
{

	//Gravity
	this->velocity.y += 1.0 * this->gravity;

	//Limit gravity
	if (std::abs(this->velocity.y) > this->velocityMaxY)
	{
		this->velocity.y = this->velocityMaxY * ((this->velocity.y < 0.f) ? -1.f : 1.f); //Checando a direção do movimento
	}


	//Deceleration
	this->velocity *= this->drag;

	//Limit deceleration
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