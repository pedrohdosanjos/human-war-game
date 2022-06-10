#include "Collider.h"
#include "MovingEntidade.h"

Collider::Collider(ListaEntidades* movingEntities, ListaEntidades* staticEntities):
	movEntities(movingEntities),
	statEntities(staticEntities)
{
}

Collider::~Collider()
{
	this->movEntities = nullptr;
	this->statEntities = nullptr;
}

void Collider::collide()
{
	Entidade* entity1 = nullptr;
	Entidade* entity2 = nullptr;

	sf::Vector2f centerDist;
	sf::Vector2f collision;


	//Colliding static with moving objects
	for (int i = 0; i < movEntities->LEs.getSize(); i++)
	{
		for (int j = 0; j < statEntities->LEs.getSize(); j++)
		{
			entity1 = (this->statEntities->LEs.getItem(j));
			entity2 = (this->movEntities->LEs.getItem(i));

			centerDist.x = entity2->getPosition().x - entity1->getPosition().x;
			centerDist.y = entity2->getPosition().y - entity1->getPosition().y;

			collision.x = abs(centerDist.x) - (entity1->getSize().y / 2.0f + entity2->getSize().y / 2.0f);
			collision.y = abs(centerDist.y) - (entity1->getSize().y / 2.0f + entity2->getSize().y / 2.0f);


			if (collision.x < 0.0f && collision.y < 0.0f)
			{
				entity2->collide(entity1, collision);
			}

		}
	}


	//Colliding two moving objects
	for (int i = 0; i < movEntities->LEs.getSize(); i++)
	{
		for (int j = i+1; j < movEntities->LEs.getSize(); j++)
		{
			entity1 = (this->movEntities->LEs.getItem(i));
			entity2 = (this->movEntities->LEs.getItem(j));

			centerDist.x = entity2->getPosition().x - entity1->getPosition().x;
			centerDist.y = entity2->getPosition().y - entity1->getPosition().y;

			collision.x = abs(centerDist.x) - (entity1->getSize().y / 2.0f + entity2->getSize().y / 2.0f);
			collision.y = abs(centerDist.y) - (entity1->getSize().y / 2.0f + entity2->getSize().y / 2.0f);


			if (collision.x < 0.0f && collision.y < 0.0f)
			{
				entity2->collide(entity1, collision);
				entity1->collide(entity2, collision);
			}

		}
	}

	//this->clear();


}

void Collider::clear()
{
	/*
	Entidade* pAux = nullptr;

	for (int i = 0; i < this->movEntities->LEs.getSize(); i++)
	{
		pAux = static_cast<MovingEntidade*>(this->movEntities->LEs.getItem(i));
		this->movEntities->LEs.pop(pAux);
	}
	*/
}

