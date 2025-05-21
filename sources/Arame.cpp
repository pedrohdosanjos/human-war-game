#include "Arame.h"

void Arame::initTexture()
{
	if (!this->textureSheet.loadFromFile("textures/ArameFarpado.png"))
	{
		std::cout << "Erro ao carregar imagem" << "\n"
				  << std::endl;
	}
}

void Arame::initSprite()
{
	this->sprite.setTexture(this->textureSheet);

	this->currentFrame = sf::IntRect(0, 0, 60, 68);
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(2.f, 2.f);
}

Arame::Arame(sf::Vector2f pos) : Obstaculo(id = fire)
{
	this->initTexture();

	this->initSprite();

	this->setPosition(pos.x, pos.y);
}

Arame::~Arame()
{
}
