#include "StaticEntidade.h"

StaticEntidade::StaticEntidade(ID id):
	Entidade(id)
{
}

StaticEntidade::~StaticEntidade()
{
}

void StaticEntidade::collide(Entidade* otherEntity, sf::Vector2f collision)
{
}
