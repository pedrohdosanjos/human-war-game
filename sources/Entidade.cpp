#include "Entidade.h"
#include <string.h>

Entidade::Entidade()
{
}

Entidade::~Entidade()
{
}

void Entidade::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}


void Entidade::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

const sf::Vector2f Entidade::getPosition() const
{
	return this->sprite.getPosition();
}