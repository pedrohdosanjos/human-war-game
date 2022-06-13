#include "MovingEntidade.h"

MovingEntidade::MovingEntidade(ID id) :
	Entidade(id)
{
}

MovingEntidade::~MovingEntidade()
{
}

void MovingEntidade::moveOnCollision(sf::Vector2f collision, Entidade* other)
{
	sf::Vector2f otherPosition = other->getPosition();

	if (collision.x > collision.y)
	{
		if (this->getPosition().x < otherPosition.x)
		{
			this->setPosition(this->getPosition().x + collision.x, this->getPosition().y);
		}
		else
		{
			this->setPosition(this->getPosition().x - collision.x, this->getPosition().y);
		}
		this->velocity.x = 0.0f;

	}
	else
	{
		if (this->getPosition().y < otherPosition.y)
		{
			this->setPosition(this->getPosition().x, this->getPosition().y + collision.y);
		}
		else
		{
			this->setPosition(this->getPosition().x, this->getPosition().y - collision.y);
		}
		this->velocity.y = 0.0f;
	}
}