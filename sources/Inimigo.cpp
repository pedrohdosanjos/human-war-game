#include "Inimigo.h"

void Inimigo::initTexture()
{
	if (!this->textureSheet.loadFromFile("player.png"))
	{
		std::cout << "Erro ao carregar imagem" << "\n" << std::endl;
	}
}

Inimigo::Inimigo(): Personagem()
{
	this->initTexture();
}

Inimigo::~Inimigo()
{
}

sf::Vector2f Inimigo::updateMovement(sf::Vector2f pos)
{
	this->animState = IDLE;

	if (this->getPosition().x > pos.x)
	{
		this->move(-0.5, 0.f);
		this->animState = MOVING_LEFT;
	}

	else if(this->getPosition().x < pos.x)
	{
		this->move(0.5, 0.f);
		this->animState = MOVING_RIGHT;
	}

	if(this->getPosition().y < pos.y)
	{
		this->move(0.f, 2.f);
		this->animState = JUMPING;
	}

	return pos;
}



