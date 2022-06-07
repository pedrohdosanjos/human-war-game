/*#include "Collider.h"

Collider::Collider()
{
}

Collider::~Collider()
{
}

void Collider::checkCollision(Player* player, Plataforma* platform)
{
	sf::Vector2f centerDist;
	sf::Vector2f collision;

	this->pPLayer = player;
	this->pPlatform = platform;

	centerDist.x = pPLayer->getPosition().x - pPlatform->getPosition().x;
	centerDist.y = pPLayer->getPosition().y - pPlatform->getPosition().y;

	collision.x = abs(centerDist.x) - (this->pPLayer->getSize().x / 2.0f + this->pPlatform->getSize().x / 2.0f);
	collision.y = abs(centerDist.y) - (this->pPLayer->getSize().y / 2.0f + this->pPlatform->getSize().y / 2.0f);
	
	if (collision.x < 0.0f && collision.y < 0.0f)
	{
		pPlatform->collide(this->pPLayer, collision);
	}
}
*/