#include "Plataforma.h"

Plataforma::Plataforma(sf::Vector2f pos) : Obstaculo(id = platform)
{
	this->initTexture();

	this->initSprite();

	this->setPosition(pos.x, pos.y);
}

Plataforma::~Plataforma()
{
}

void Plataforma::initSprite()
{
	this->sprite.setTexture(this->textureSheet);

	this->currentFrame = sf::IntRect(0, 0, 300, 75);
	this->sprite.setTextureRect(this->currentFrame);
	// this->sprite.setTextureRect(sf::IntRect(0, 0, 100, 22));
}

void Plataforma::initTexture()
{
	if (!this->textureSheet.loadFromFile("textures/plataforma.png"))
	{
		std::cout << "Erro ao carregar imagem" << "\n"
				  << std::endl;
	}
}