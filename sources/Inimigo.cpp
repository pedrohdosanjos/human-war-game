#include "Inimigo.h"
#include "Player.h"

void Inimigo::initPhysics()
{
	this->velocityMax = 15.f;
	this->velocityMin = 1.f;
	this->acceleration = 3.f;
	this->drag = 0.8f;
	this->gravity = 4.f;
	this->velocityMaxY = 80.f;
}


Inimigo::Inimigo(Player* pP,int life, const float attCooldown, const float attackingTime, ID id) :
	Personagem(life, attCooldown, attackingTime,id),
	pPlayer(pP)
{
	this->initPhysics();

}

Inimigo::~Inimigo()
{
	pPlayer = nullptr;
}


sf::Vector2f Inimigo::updateMovement(sf::Vector2f pos)
{
	this->animState = IDLE;

	if (this->getPosition().x - pos.x < 600 && this->getPosition().x > pos.x)
	{
		this->move(-1.f, 0.f);
		this->animState = MOVING_LEFT;
	}

	else if (this->getPosition().x < pos.x)
	{
		this->move(1.f, 0.f);
		this->animState = MOVING_RIGHT;
	}

	return pos;
}


void Inimigo::collide(Entidade* otherEntity, sf::Vector2f intersect)
{
	if (otherEntity->getID() == platform)
	{
		this->moveOnCollision(intersect, otherEntity);
	}

	else if (otherEntity->getID() == fire)
	{
		this->moveOnCollision(intersect, otherEntity);
	}

	else if (otherEntity->getID() == player)
	{
		
		if (pPlayer != nullptr)
		{
			sf::Vector2f centerDist;

			centerDist.x = (otherEntity->getPosition().x + otherEntity->getSize().x / 2.0f) - (this->getPosition().x + otherEntity->getSize().x / 2.0f);
			intersect.x = abs(centerDist.x) - ((this->getSize().x - this->pPlayer->getSwordDistance() * 2.0f) / 2.0f + otherEntity->getSize().x / 2.0f);

			if (intersect.x < 0.0f && intersect.y < 0.0f)
			{
				if (this->isAttacking())
				{
					this->pPlayer->receiveDamage(this->getDamage());
				}
			}
		}
		this->moveOnCollision(intersect, otherEntity);
	}
}

void Inimigo::setpPlayer(Player* pP)
{
	if (pP == nullptr)
	{
		std::cout << "Erro:Ponteiro para Player inacessivel" << std::endl;
		return;
	}
	this->pPlayer = pP;

}

sf::Vector2f Inimigo::getPlayerPosition()
{
	return this->pPlayer->getPosition();
}

void Inimigo::receiveDamage(const int damage)
{
	this->life -= damage;

	if (life <= 0)
	{
		this->alive = false;
	}
}
