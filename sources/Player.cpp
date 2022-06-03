#include "Player.h"


void Player::initPhysics()
{
	this->velocityMax = 20.f;
	this->velocityMin = 1.f;
	this->acceleration = 3.3f;
	this->drag = 0.87f;
	this->gravity = 4.f;
	this->velocityMaxY = 15.f;
}

void Player::initVariables()
{
	this->animState = IDLE;

}

void Player::initTexture()
{
	if (!this->textureSheet.loadFromFile("player.png"))
	{
		std::cout << "Erro ao carregar imagem" << "\n" << std::endl;
	}
}

void Player::initSprite()
{
	this->sprite.setTexture(this->textureSheet);
	this->currentFrame = sf::IntRect(0, 0, 40, 50); //40 por 50 

	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(3.f, 3.f);
}

void Player::initAnimations()
{
	this->animationTimer.restart();
	this->animationSwitch = true; //default
}

Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initAnimations();
	this->initPhysics();

}

Player::~Player()
{
}

const bool& Player::getAnimSwitch()
{
	bool anim_switch = this->animationSwitch;

	if (this->animationSwitch)
		this->animationSwitch = false;

	return anim_switch;
}

const sf::FloatRect Player::getGlobalBounds() const
{
	return this->sprite.getGlobalBounds();
}

const sf::Vector2f Player::getPosition() const
{
	return this->sprite.getPosition();
}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Player::resetVelocityY()
{
	this->velocity.y = 0.f;
}

void Player::updateMovement()
{

	this->animState = IDLE;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) //Left
	{
		this->move(-1.f, 0.f);
		this->animState = MOVING_LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))//Right
	{
		this->move(1.f, 0.f);
		this->animState = MOVING_RIGHT;
	}

}

void Player::updateAnimations()
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

void Player::update()
{
	this->updateMovement();
	this->updateAnimations();
	this->updatePhysics();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);

	sf::CircleShape circ;
	circ.setFillColor(sf::Color::Red);
	circ.setRadius(2.f);
	circ.setPosition(this->sprite.getPosition());

	target.draw(circ);
}

void Player::resetAnimationTimer()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void Player::move(const float x, const float y)
{
	//Acceleration
	this->velocity.x += x * this->acceleration;



	//Limit velocity
	if (std::abs(this->velocity.x) > this->velocityMax)
	{
		this->velocity.x = this->velocityMax * ((this->velocity.x < 0.f) ? -1.f : 1.f); //Checando a direção do movimento
	}
}


void Player::updatePhysics()
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
